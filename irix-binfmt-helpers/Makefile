PREFIX:=/opt/irix/sgug/qemu

qemu-irix-wrapper: qemu-irix-wrapper.c Makefile
	gcc -static -O2 -o qemu-irix-wrapper qemu-irix-wrapper.c
	ln -sf qemu-irix-wrapper qemu-irixn32-wrapper
	ln -sf qemu-irix-wrapper qemu-irix64-wrapper

install: qemu-irix-wrapper
	cp -a qemu-irix-binfmt qemu-irix-wrapper qemu-irixn32-wrapper qemu-irix64-wrapper $(PREFIX)/bin

