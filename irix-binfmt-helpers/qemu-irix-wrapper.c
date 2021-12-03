#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int
main(int argc, char *argv[])
{
    char **newargv = (char**) calloc(argc + 5, sizeof(char *));
    char cmd[256];
    char *p;

    FILE *log = 0;

    if (argc < 2) {
        fprintf(stderr, "qemu-irix-wrapper: missing exe and argv0\n");
        exit(1);
    }

    strcpy(cmd, argv[0]);
    if ((p = strrchr(cmd, '/')))
        *p = 0;

    if (strstr(argv[0], "n32"))
        strcat(cmd, "/qemu-irixn32");
    else if (strstr(argv[0], "n64"))
        strcat(cmd, "/qemu-irix64");
    else
        strcat(cmd, "/qemu-irix");

    setenv("QEMU_RESERVED_VA", "2048M", 0);
    setenv("QEMU_SET_ENV", "LANG=C", 0);
    setenv("QEMU_IRIXPRDA", "1", 0);

    // are we outside the IRIX chroot?
    struct stat st;
    if (stat("/lib32/rld", &st) != 0) {
        // outside the irix root
        const char* irixroot = getenv("IRIXROOT");
        if (irixroot)
            setenv("QEMU_LD_PREFIX", irixroot, 0);
        //log = fopen("/opt/irix/root/tmp/QLOG", "a");
    } else {
        // inside
        //log = fopen("/tmp/QLOG", "a");
    }

    char* exe = argv[1];
    char* argv0 = argv[2];

    newargv[0] = cmd;
    newargv[1] = "-0";
    newargv[2] = argv0;
    newargv[3] = exe;

    for (int i = 3; i < argc; i++) {
        newargv[i+1] = argv[i];
    }
    newargv[argc+1] = NULL;

    if (log) {
        fprintf(log, "execv: '%s' argv: ", cmd);
        for (int i = 0; i < argc+1; i++) {
            fprintf(log, "'%s' ", newargv[i]);
        }
        fputs("\n", log);
        fclose(log);
    }

    execv(cmd, newargv);
}
