Scripts and tools mostly have harcoded paths of /opt/irix/root and /opt/irix/sgug.  You need:

1. An IRIX filesystem root in /opt/irix/root
2. A prefix of /opt/irix/sgug for host (Linux) files
3. A symlink in /opt/irix/sgug/qemu that points to a real directory in /opt/irix/root/opt/irix/sgug/qemu
  -- NOTE -- READ THE ABOVE A SECOND TIME! --
  The symlink needs to be in /opt/irix/sgug/qemu, while the actual physical directory is in /opt/irix/root/opt/irix/sgug/qemu
  so that when chrooted inside /opt/irix/root, the path is identical as outside the chroot.
4. Some real device entries in /opt/irix/root/dev:
    cd /opt/irix/root/dev
    mknod -m 0666 zero c 1 5
    mknod -m 0666 null c 1 3
    mknod -m 0666 random c 1 8
    mknod -m 0666 urandom c 1 9
    mknod -m 0666 tty c 5 0

To build (set up the symblink first, or move stuff around after!):
==================================================================

./configure --static --prefix=/opt/irix/sgug/qemu --target-list=irix-linux-user,irixn32-linux-user,irix64-linux-user --disable-werror
make install
make -C irix-binfmt-helpers install

To use:
=======

First setup the binfmt helpers:

- sudo /opt/irix/sgug/qemu/bin/qemu-irix-binfmt

Export IRIXROOT env var (only used outside of chroot by the wrapper):

- export IRIXROOT=/opt/irix/root

Test:
=====

- /opt/irix/root/bin/ls
[should see ls output]

- sudo chroot /opt/irix/root /bin/ls
[should see ls output]

- sudo chroot /opt/irix/root /bin/sh
[should get a shell prompt]


