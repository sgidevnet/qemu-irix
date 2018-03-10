/* Code to mangle pathnames into those matching a given prefix.
   eg. open("/lib/foo.so") => open("/usr/gnemul/i386-linux/lib/foo.so");

   The assumption is that this area does not change.
*/
#include "qemu/osdep.h"
#include <sys/param.h>
#include <dirent.h>
#include "qemu/cutils.h"
#include "qemu/path.h"

struct pathelem
{
    /* Name of this, eg. lib */
    char *name;
    /* Full path name, eg. /usr/gnemul/x86-linux/lib. */
    char *pathname;
    /* Entry type */
    unsigned char type;
    /* Parent */
    struct pathelem *parent;
    /* Children */
    int num_entries;
    struct pathelem **entries;
};

static struct pathelem **base;
int base_count;

/* First N chars of S1 match S2, and S2 is N chars long. */
static int strneq(const char *s1, unsigned int n, const char *s2)
{
    unsigned int i;

    for (i = 0; i < n; i++)
        if (s1[i] != s2[i])
            return 0;
    return s2[i] == 0;
}

static struct pathelem *add_entry(struct pathelem *root, const char *name,
                                  unsigned type);

static struct pathelem *new_entry(const char *root, struct pathelem *parent,
                                  const char *name, unsigned char type)
{
    struct pathelem *new = g_malloc(sizeof(*new));
    new->name = g_strdup(name);
    new->pathname = g_strdup_printf("%s/%s", root, name);
    new->type = type;
    new->entries = NULL;
    new->num_entries = -1;
    return new;
}

#define streq(a,b) (strcmp((a), (b)) == 0)

/* Not all systems provide this feature */
#if defined(DT_DIR) && defined(DT_UNKNOWN) && defined(DT_LNK)
# define dirent_type(dirent) ((dirent)->d_type)
# define is_dir_maybe(type) \
    ((type) == DT_DIR || (type) == DT_UNKNOWN || (type) == DT_LNK)
#else
# define dirent_type(dirent) (1)
# define is_dir_maybe(type)  (type)
#endif

static struct pathelem *add_dir_maybe(struct pathelem *path)
{
    DIR *dir;

    path->num_entries = 0;
    if ((dir = opendir(path->pathname)) != NULL) {
        struct dirent *dirent;

        while ((dirent = readdir(dir)) != NULL) {
            if (!streq(dirent->d_name,".") && !streq(dirent->d_name,"..")){
                path = add_entry(path, dirent->d_name, dirent_type(dirent));
            }
        }
        closedir(dir);
    }
    return path;
}

static struct pathelem *add_entry(struct pathelem *root, const char *name,
                                  unsigned type)
{
    struct pathelem **e;

    root->num_entries++;

    root->entries = g_realloc(root->entries,
                            sizeof(root->entries[0])*root->num_entries);
    e = &root->entries[root->num_entries-1];

    *e = new_entry(root->pathname, root, name, type);
    return root;
}

/* This needs to be done after tree is stabilized (ie. no more reallocs!). */
static void set_parents(struct pathelem *child, struct pathelem *parent)
{
    int i;

    child->parent = parent;
    for (i = 0; i < child->num_entries; i++)
        set_parents(child->entries[i], child);
}

/* FIXME: Doesn't handle DIR/.. where DIR is not in emulated dir. */
static const char *
follow_path(struct pathelem *cursor, const char *name)
{
    int i, namelen;

    name += strspn(name, "/");
    namelen = strcspn(name, "/");

    if (namelen == 0)
        return cursor->pathname;

    if (strneq(name, namelen, ".."))
        return follow_path(cursor->parent, name + namelen);

    if (strneq(name, namelen, "."))
        return follow_path(cursor, name + namelen);

    if (cursor->num_entries < 0) {
        static char path[255];
        if (is_dir_maybe(cursor->type))
            add_dir_maybe(cursor);
        else if (cursor->type == DT_LNK &&
                        readlink(cursor->pathname, path, sizeof(path)) >= 0) {
            if (*path != '/')
                add_dir_maybe(cursor);
        } else
            cursor->num_entries = 0;
        if (cursor->num_entries > 0)
            set_parents(cursor, cursor->parent);
    }

    for (i = 0; i < cursor->num_entries; i++)
        if (strneq(name, namelen, cursor->entries[i]->name))
            return follow_path(cursor->entries[i], name + namelen);

    /* Not found */
    return NULL;
}

void init_paths(const char *prefix_list)
{
    char pref_buf[PATH_MAX];
    int count = base_count;
    char *list, *prefix, *p;

    list = g_strdup(prefix_list);

    for (p = list; *p; p++) count += (*p == ':');
    base = g_realloc(base, sizeof(*base) * (count + 1));

    for (prefix = strtok(list, ":"); prefix; prefix = strtok(NULL, ":")) {
        if (prefix[0] == '\0' || !strcmp(prefix, "/"))
            continue;

        if (prefix[0] != '/') {
            char *cwd = getcwd(NULL, 0);
            size_t pref_buf_len = sizeof(pref_buf);

            if (!cwd)
                abort();
            pstrcpy(pref_buf, sizeof(pref_buf), cwd);
            pstrcat(pref_buf, pref_buf_len, "/");
            pstrcat(pref_buf, pref_buf_len, prefix);
            free(cwd);
        } else
            pstrcpy(pref_buf, sizeof(pref_buf), prefix + 1);

        base[base_count] = new_entry("", NULL, pref_buf, DT_DIR);
        base[base_count] = add_dir_maybe(base[base_count]);

        if (base[base_count]->num_entries <= 0) {
            g_free(base[base_count]->pathname);
            g_free(base[base_count]->name);
            g_free(base[base_count]);
        } else {
            set_parents(base[base_count], base[base_count]);
            base_count ++;
        }
    }
    g_free(list);
}

/* Look for path in emulation dir, otherwise return name. */
const char *path(const char *name)
{
    const char *p;
    int i;

    /* Only do absolute paths: quick and dirty, but should mostly be OK.
       Could do relative by tracking cwd. */
    if (!base || !name || name[0] != '/')
        return name;

    for (i = 0; i < base_count; i++) {
        if ((p = follow_path(base[i], name)))
            return p;
    }

    return name;
}
