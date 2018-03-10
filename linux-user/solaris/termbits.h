/* from asm/termbits.h */

#define TARGET_NCCS 19

struct target_termios {
    unsigned int c_iflag;               /* input mode flags */
    unsigned int c_oflag;               /* output mode flags */
    unsigned int c_cflag;               /* control mode flags */
    unsigned int c_lflag;               /* local mode flags */
    unsigned char c_cc[TARGET_NCCS];                /* control characters */
};

/* c_cc characters */
#define TARGET_VINTR    0
#define TARGET_VQUIT    1
#define TARGET_VERASE   2
#define TARGET_VKILL    3
#define TARGET_VEOF     4
#define TARGET_VEOL     5
#define TARGET_VEOL2    6
#define TARGET_VSWTC    7
#define TARGET_VSTART   8
#define TARGET_VSTOP    9

#define TARGET_VSUSP    10
#define TARGET_VDSUSP   11  /* SunOS POSIX nicety I do believe... */
#define TARGET_VREPRINT 12
#define TARGET_VDISCARD 13
#define TARGET_VWERASE  14
#define TARGET_VLNEXT   15

/* Kernel keeps vmin/vtime separated, user apps assume vmin/vtime is
 * shared with eof/eol
 */
#define TARGET_VMIN     TARGET_VEOF
#define TARGET_VTIME    TARGET_VEOL

/* c_iflag bits */
#define TARGET_IGNBRK	0x00000001
#define TARGET_BRKINT	0x00000002
#define TARGET_IGNPAR	0x00000004
#define TARGET_PARMRK	0x00000008
#define TARGET_INPCK	0x00000010
#define TARGET_ISTRIP	0x00000020
#define TARGET_INLCR	0x00000040
#define TARGET_IGNCR	0x00000080
#define TARGET_ICRNL	0x00000100
#define TARGET_IUCLC	0x00000200
#define TARGET_IXON	0x00000400
#define TARGET_IXANY	0x00000800
#define TARGET_IXOFF	0x00001000
#define TARGET_IMAXBEL	0x00002000
#define TARGET_IUTF8	0x00004000

/* c_oflag bits */
#define TARGET_OPOST	0x00000001
#define TARGET_OLCUC	0x00000002
#define TARGET_ONLCR	0x00000004
#define TARGET_OCRNL	0x00000008
#define TARGET_ONOCR	0x00000010
#define TARGET_ONLRET	0x00000020
#define TARGET_OFILL	0x00000040
#define TARGET_OFDEL	0x00000080
#define TARGET_NLDLY	0x00000100
#define   TARGET_NL0	0x00000000
#define   TARGET_NL1	0x00000100
#define TARGET_CRDLY	0x00000600
#define   TARGET_CR0	0x00000000
#define   TARGET_CR1	0x00000200
#define   TARGET_CR2	0x00000400
#define   TARGET_CR3	0x00000600
#define TARGET_TABDLY	0x00001800
#define   TARGET_TAB0	0x00000000
#define   TARGET_TAB1	0x00000800
#define   TARGET_TAB2	0x00001000
#define   TARGET_TAB3	0x00001800
#define   TARGET_XTABS	0x00001800
#define TARGET_BSDLY	0x00002000
#define   TARGET_BS0	0x00000000
#define   TARGET_BS1	0x00002000
#define TARGET_VTDLY	0x00004000
#define   TARGET_VT0	0x00000000
#define   TARGET_VT1	0x00004000
#define TARGET_FFDLY	0x00008000
#define   TARGET_FF0	0x00000000
#define   TARGET_FF1	0x00008000
#define TARGET_PAGEOUT 0x00010000  /* SUNOS specific */
#define TARGET_WRAP    0x00020000  /* SUNOS specific */

/* c_cflag bit meaning */
#define TARGET_CBAUD	  0x0020000f
#define  TARGET_B0	  0x00000000   /* hang up */
#define  TARGET_B50	  0x00000001
#define  TARGET_B75	  0x00000002
#define  TARGET_B110	  0x00000003
#define  TARGET_B134	  0x00000004
#define  TARGET_B150	  0x00000005
#define  TARGET_B200	  0x00000006
#define  TARGET_B300	  0x00000007
#define  TARGET_B600	  0x00000008
#define  TARGET_B1200	  0x00000009
#define  TARGET_B1800	  0x0000000a
#define  TARGET_B2400	  0x0000000b
#define  TARGET_B4800	  0x0000000c
#define  TARGET_B9600	  0x0000000d
#define  TARGET_B19200	  0x0000000e
#define  TARGET_B38400	  0x0000000f
#define TARGET_EXTA      B19200
#define TARGET_EXTB      B38400
#define  TARGET_CSIZE    0x00000030
#define   TARGET_CS5	  0x00000000
#define   TARGET_CS6	  0x00000010
#define   TARGET_CS7	  0x00000020
#define   TARGET_CS8	  0x00000030
#define TARGET_CSTOPB	  0x00000040
#define TARGET_CREAD	  0x00000080
#define TARGET_PARENB	  0x00000100
#define TARGET_PARODD	  0x00000200
#define TARGET_HUPCL	  0x00000400
#define TARGET_CLOCAL	  0x00000800
#define TARGET_CBAUDEX   0x00200000
/* We'll never see these speeds with the Zilogs, but for completeness... */
#define  TARGET_B57600   (TARGET_CBAUDEX+1)
#define  TARGET_B115200  (TARGET_CBAUDEX+2)
#define  TARGET_B230400  (TARGET_CBAUDEX+3)
#define  TARGET_B460800  (TARGET_CBAUDEX+4)
/* This is what we can do with the Zilogs. */
#define  TARGET_B76800   (TARGET_CBAUDEX+5)
/* This is what we can do with the SAB82532. */
#define  TARGET_B153600  (TARGET_CBAUDEX+6)
#define  TARGET_B307200  (TARGET_CBAUDEX+7)
#define  TARGET_B614400  (TARGET_CBAUDEX+8)
#define  TARGET_B921600  (TARGET_CBAUDEX+9)
/* And these are the rest... */
#define  TARGET_B500000  (TARGET_CBAUDEX+10)
#define  TARGET_B576000  (TARGET_CBAUDEX+11)
#define TARGET_B1000000  (TARGET_CBAUDEX+12)
#define TARGET_B1152000  (TARGET_CBAUDEX+13)
#define TARGET_B1500000  (TARGET_CBAUDEX+14)
#define TARGET_B2000000  (TARGET_CBAUDEX+15)
/* These have totally bogus values and nobody uses them
   so far. Later on we'd have to use say 0x10000x and
   adjust CBAUD constant and drivers accordingly.
#define B2500000  0x00001010
#define B3000000  0x00001011
#define B3500000  0x00001012
#define B4000000  0x00001013  */
#define TARGET_CIBAUD	  0x004f0000  /* input baud rate (not used) */
#define TARGET_CMSPAR	  0x40000000  /* mark or space (stick) parity */
#define TARGET_CRTSCTS	  0x80000000  /* flow control */

/* c_lflag bits */
#define TARGET_ISIG	0x00000001
#define TARGET_ICANON	0x00000002
#define TARGET_XCASE	0x00000004
#define TARGET_ECHO	0x00000008
#define TARGET_ECHOE	0x00000010
#define TARGET_ECHOK	0x00000020
#define TARGET_ECHONL	0x00000040
#define TARGET_NOFLSH	0x00000080
#define TARGET_TOSTOP	0x00000100
#define TARGET_ECHOCTL	0x00000200
#define TARGET_ECHOPRT	0x00000400
#define TARGET_ECHOKE	0x00000800
#define TARGET_DEFECHO  0x00001000  /* SUNOS thing, what is it? */
#define TARGET_FLUSHO	0x00002000
#define TARGET_PENDIN	0x00004000
#define TARGET_IEXTEN	0x00008000

/* ioctls */
#define TARGET_IO_(t,n)	(((t)<<8)|(n))

/* Big T */
#define TARGET_TCGETA		TARGET_IO_('T', 1)
#define TARGET_TCSETA		TARGET_IO_('T', 2)
#define TARGET_TCSETAW		TARGET_IO_('T', 3)
#define TARGET_TCSETAF		TARGET_IO_('T', 4)
#define TARGET_TCSBRK		TARGET_IO_('T', 5)
#define TARGET_TCXONC		TARGET_IO_('T', 6)
#define TARGET_TCFLSH		TARGET_IO_('T', 7)
#define TARGET_TCGETS		TARGET_IO_('T', 13)
#define TARGET_TCSETS		TARGET_IO_('T', 14)
#define TARGET_TCSETSW		TARGET_IO_('T', 15)
#define TARGET_TCSETSF		TARGET_IO_('T', 16)

#define TARGET_TIOCGSOFTCAR	TARGET_IO_('T', 105)
#define TARGET_TIOCSSOFTCAR	TARGET_IO_('T', 106)
//#define __TIOCUCNTL       _IOCTL('T', 102) /* SunOS Specific */
#define TARGET_TIOCSWINSZ	TARGET_IO_('T', 103)
#define TARGET_TIOCGWINSZ	TARGET_IO_('T', 104)

//#define __TIOCREMOTE      _IOCTL('t', 30) /* SunOS Specific */
/* Note that all the ioctls that are not available in Linux have a
 * double underscore on the front to: a) avoid some programs to
 * thing we support some ioctls under Linux (autoconfiguration stuff)
 */
/* Little t */
#define TARGET_TIOCGETD	TARGET_IO_('t', 0)
#define TARGET_TIOCSETD	TARGET_IO_('t', 1)
//#define __TIOCHPCL        _IOCTL('t') /* SunOS Specific */
//#define __TIOCMODG        _IOCTL('t', 3) /* SunOS Specific */
//#define __TIOCMODS        _IOCTL('t', 4) /* SunOS Specific */
//#define __TIOCGETP        _IOCTL('t', 8) /* SunOS Specific */
//#define __TIOCSETP        _IOCTL('t', 9) /* SunOS Specific */
//#define __TIOCSETN        _IOCTL('t', 10) /* SunOS Specific */
#define TARGET_TIOCEXCL	TARGET_IO_('t', 13)
#define TARGET_TIOCNXCL	TARGET_IO_('t', 14)
//#define __TIOCFLUSH       _IOCTL('t', 16) /* SunOS Specific */
//#define __TIOCSETC        _IOCTL('t', 17) /* SunOS Specific */
//#define __TIOCGETC        _IOCTL('t', 18) /* SunOS Specific */
//#define __TIOCTCNTL       _IOCTL('t', 32) /* SunOS Specific */
//#define __TIOCSIGNAL      _IOCTL('t', 31) /* SunOS Specific */
//#define __TIOCSETX        _IOCTL('t', 34) /* SunOS Specific */
//#define __TIOCGETX        _IOCTL('t', 35) /* SunOS Specific */
#define TARGET_TIOCCONS	TARGET_IO_('t', 36)
//#define __TIOCSSIZE     _IOCTL('t', 37) /* SunOS Specific */
//#define __TIOCGSIZE     _IOCTL('t', 38) /* SunOS Specific */
#define TARGET_TIOCMGET	TARGET_IO_('t', 29)
#define TARGET_TIOCMBIC	TARGET_IO_('t', 28)
#define TARGET_TIOCMBIS	TARGET_IO_('t', 27)
#define TARGET_TIOCMSET	TARGET_IO_('t', 26)
#define TARGET_TIOCSTART       TARGET_IO_('t', 110)
#define TARGET_TIOCSTOP        TARGET_IO_('t', 111)
#define TARGET_TIOCPKT		TARGET_IO_('t', 112)
#define TARGET_TIOCNOTTY	TARGET_IO_('t', 113)
#define TARGET_TIOCSTI		TARGET_IO_('t', 23)
#define TARGET_TIOCOUTQ	TARGET_IO_('t', 115)
//#define __TIOCGLTC        _IOCTL('t', 116) /* SunOS Specific */
//#define __TIOCSLTC        _IOCTL('t', 117) /* SunOS Specific */
/* 118 is the non-posix setpgrp tty ioctl */
/* 119 is the non-posix getpgrp tty ioctl */
//#define __TIOCCDTR        TARGET_IO_('t', 120) /* SunOS Specific */
//#define __TIOCSDTR        TARGET_IO_('t', 121) /* SunOS Specific */
#define TARGET_TIOCCBRK        TARGET_IO_('t', 122)
#define TARGET_TIOCSBRK        TARGET_IO_('t', 123)
//#define __TIOCLGET        TARGET_IO_('t', 124) /* SunOS Specific */
//#define __TIOCLSET        TARGET_IO_('t', 125) /* SunOS Specific */
//#define __TIOCLBIC        TARGET_IO_('t', 126) /* SunOS Specific */
//#define __TIOCLBIS        TARGET_IO_('t', 127) /* SunOS Specific */
//#define __TIOCISPACE      TARGET_IO_('t', 128) /* SunOS Specific */
//#define __TIOCISIZE       TARGET_IO_('t', 129) /* SunOS Specific */
#define TARGET_TIOCSPGRP	TARGET_IO_('t', 21)
#define TARGET_TIOCGPGRP	TARGET_IO_('t', 20)
#define TARGET_TIOCSCTTY	TARGET_IO_('t', 132)
#define TARGET_TIOCGSID	TARGET_IO_('t', 22)
/* Get minor device of a pty master's FD -- Solaris equiv is ISPTM */
#define TARGET_TIOCGPTN	TARGET_IO_('t', 134) /* Get Pty Number */
#define TARGET_TIOCSPTLCK	TARGET_IO_('t', 135) /* Lock/unlock PTY */

/* Little f */
#define TARGET_FIOCLEX		TARGET_IO('f', 1)
#define TARGET_FIONCLEX	TARGET_IO('f', 2)
#define TARGET_FIOASYNC	TARGET_IOW('f', 125, int)
#define TARGET_FIONBIO		TARGET_IOW('f', 126, int)
#define TARGET_FIONREAD	TARGET_IOR('f', 127, int)
#define TARGET_TIOCINQ		TARGET_FIONREAD

/* SCARY Rutgers local SunOS kernel hackery, perhaps I will support it
 * someday.  This is completely bogus, I know...
 */
//#define __TCGETSTAT       TARGET_IO('T', 200) /* Rutgers specific */
//#define __TCSETSTAT       TARGET_IO('T', 201) /* Rutgers specific */

/* Linux specific, no SunOS equivalent. */
#define TARGET_TIOCLINUX	0x541C
#define TARGET_TIOCGSERIAL	0x541E
#define TARGET_TIOCSSERIAL	0x541F
#define TARGET_TCSBRKP		0x5425
#define TARGET_TIOCTTYGSTRUCT	0x5426
#define TARGET_TIOCSERCONFIG	0x5453
#define TARGET_TIOCSERGWILD	0x5454
#define TARGET_TIOCSERSWILD	0x5455
#define TARGET_TIOCGLCKTRMIOS	0x5456
#define TARGET_TIOCSLCKTRMIOS	0x5457
#define TARGET_TIOCSERGSTRUCT	0x5458 /* For debugging only */
#define TARGET_TIOCSERGETLSR   0x5459 /* Get line status register */
#define TARGET_TIOCSERGETMULTI 0x545A /* Get multiport config  */
#define TARGET_TIOCSERSETMULTI 0x545B /* Set multiport config */
#define TARGET_TIOCMIWAIT	0x545C /* Wait input */
#define TARGET_TIOCGICOUNT	0x545D /* Read serial port inline interrupt counts */
