/*
 * Solaris syscalls. This is derived from Netbsd svr4_32_sysent.c and Solaris 7
 * syscall.h, with extensions from Illumos for stuff undefined in Solaris 7.
 */

#define	TARGET_NR_syscall	0
#define	TARGET_NR_exit		1
#define	TARGET_NR_fork		2
#define	TARGET_NR_read		3
#define	TARGET_NR_write		4
#define	TARGET_NR_open		5
#define	TARGET_NR_close		6
#define	TARGET_NR_linkat	7	/* wait in Solaris 7 */
#define	TARGET_NR_creat		8
#define	TARGET_NR_link		9
#define	TARGET_NR_unlink	10
#define	TARGET_NR_symlinkat	11	/* exec in Solaris 7 */
#define	TARGET_NR_chdir		12
#define	TARGET_NR_time		13
#define	TARGET_NR_mknod		14
#define	TARGET_NR_chmod		15
#define	TARGET_NR_chown		16
#define	TARGET_NR_brk		17
#define	TARGET_NR_stat		18
#define	TARGET_NR_lseek		19
#define	TARGET_NR_getpid	20
#define	TARGET_NR_mount		21
#define	TARGET_NR_readlinkat	22	/* umount in Solaris 7 */
#define	TARGET_NR_setuid	23
#define	TARGET_NR_getuid	24
#define	TARGET_NR_stime		25
#define	TARGET_NR_pcsample	26
#define	TARGET_NR_alarm		27
#define	TARGET_NR_fstat		28
#define	TARGET_NR_pause		29
#define	TARGET_NR_utime		30
#define	TARGET_NR_stty		31
#define	TARGET_NR_gtty		32
#define	TARGET_NR_access	33
#define	TARGET_NR_nice		34
#define	TARGET_NR_statfs	35
#define	TARGET_NR_sync		36
#define	TARGET_NR_kill		37
#define	TARGET_NR_fstatfs	38
#define	TARGET_NR_pgrpsys	39
#define	TARGET_NR_xenix		40	/* uucopystr for Solaris 10 */
#define	TARGET_NR_dup		41
#define	TARGET_NR_pipe		42
#define	TARGET_NR_times		43
#define	TARGET_NR_profil	44
#define	TARGET_NR_faccessat	45	/* plock in Solaris 7 */
#define	TARGET_NR_setgid	46
#define	TARGET_NR_getgid	47
#define	TARGET_NR_mknodat	48	/* signal in Solaris 7 */
#define	TARGET_NR_msgsys	49
#define	TARGET_NR_sysarch	50
#define	TARGET_NR_acct		51
#define	TARGET_NR_shmsys	52
#define	TARGET_NR_semsys	53
#define	TARGET_NR_ioctl		54
#define	TARGET_NR_uadmin	55
#define TARGET_NR_fchownat	56	/* undefined for Solaris 7 */
#define	TARGET_NR_utssyssunos	57
#define	TARGET_NR_fdsync	58
#define	TARGET_NR_execve	59
#define	TARGET_NR_umask		60
#define	TARGET_NR_chroot	61
#define	TARGET_NR_fcntl		62
#define	TARGET_NR_ulimit	63
#define TARGET_NR_renameat	64	/* undefined in Solaris 7 */
#define TARGET_NR_unlinkat	65	/* undefined in Solaris 7 */
#define TARGET_NR_fstatat	66	/* undefined in Solaris 7 */
#define TARGET_NR_fstatat64	67	/* undefined in Solaris 7 */
#define TARGET_NR_openat	68	/* undefined in Solaris 7 */
#define TARGET_NR_openat64	69	/* undefined in Solaris 7 */
#define	TARGET_NR_tasksys	70	/* undefined in Solaris 7 */
#define	TARGET_NR_acctctl	71	/* undefined in Solaris 7 */
#define	TARGET_NR_exacctsys	72	/* undefined in Solaris 7 */
#define	TARGET_NR_getpagesizes	73	/* undefined in Solaris 7 */
#define	TARGET_NR_rctlsys	74	/* undefined in Solaris 7 */
#define	TARGET_NR_sidsys	75	/* undefined in Solaris 7 */
#define	TARGET_NR_fsat		76	/* undefined in Solaris 7 */
#define	TARGET_NR_lwp_park	77	/* undefined in Solaris 7 */
#define	TARGET_NR_sendfilev	78	/* undefined in Solaris 7 */
#define	TARGET_NR_rmdir		79
#define	TARGET_NR_mkdir		80
#define	TARGET_NR_getdents	81
#define	TARGET_NR_privsys	82	/* undefined in Solaris 7 */
#define	TARGET_NR_ucredsys	83	/* undefined in Solaris 7 */
#define	TARGET_NR_sysfs		84
#define	TARGET_NR_getmsg	85
#define	TARGET_NR_putmsg	86
#define	TARGET_NR_poll		87
#define	TARGET_NR_lstat		88
#define	TARGET_NR_symlink	89
#define	TARGET_NR_readlink	90
#define	TARGET_NR_setgroups	91
#define	TARGET_NR_getgroups	92
#define	TARGET_NR_fchmod	93
#define	TARGET_NR_fchown	94
#define	TARGET_NR_sigprocmask	95
#define	TARGET_NR_sigsuspend	96
#define	TARGET_NR_sigaltstack	97
#define	TARGET_NR_sigaction	98
#define	TARGET_NR_sigpendingsys	99
#define	TARGET_NR_context	100
#define	TARGET_NR_fchmodat	101	/* evsys in Solaris 7 */
#define	TARGET_NR_mkdirat	102	/* evtrapret in Solaris 7 */
#define	TARGET_NR_statvfs	103
#define	TARGET_NR_fstatvfs	104
#define	TARGET_NR_getloadavg	105
#define	TARGET_NR_nfssys	106
#define	TARGET_NR_waitid	107
#define	TARGET_NR_sigsendsys	108
#define	TARGET_NR_hrtsys	109
#define TARGET_NR_acancel	110	/* utimesys in Solaris 10 */
#define	TARGET_NR_async		111	/* sigresend in Solaris 10 */
#define	TARGET_NR_priocntlsys	112
#define	TARGET_NR_pathconf	113
#define	TARGET_NR_mincore	114
#define	TARGET_NR_mmap		115
#define	TARGET_NR_mprotect	116
#define	TARGET_NR_munmap	117
#define	TARGET_NR_fpathconf	118
#define	TARGET_NR_vfork		119
#define	TARGET_NR_fchdir	120
#define	TARGET_NR_readv		121
#define	TARGET_NR_writev	122
#define	TARGET_NR_xstat		123	/* preadv in Solaris 10 */
#define	TARGET_NR_lxstat	124	/* pwritev in Solaris 10 */
#define	TARGET_NR_fxstat	125	/* undefined in Solaris 10 */
#define	TARGET_NR_xmknod	126	/* undefined in Solaris 10 */
#define TARGET_NR_clocal	127	/* mmapobj in Solaris 10 */
#define	TARGET_NR_setrlimit	128
#define	TARGET_NR_getrlimit	129
#define	TARGET_NR_lchown	130
#define	TARGET_NR_memcntl	131
#define	TARGET_NR_getpmsg	132
#define	TARGET_NR_putpmsg	133
#define	TARGET_NR_rename	134
#define	TARGET_NR_unamesunos	135
#define	TARGET_NR_setegid	136
#define	TARGET_NR_sysconfig	137
#define	TARGET_NR_adjtime	138
#define	TARGET_NR_sysinfosunos	139
#define	TARGET_NR_sharefs	140	/* undefined for Solaris 7 */
#define	TARGET_NR_seteuid	141
#define	TARGET_NR_forksys	142	/* vtrace for Solaris 7 */
#define	TARGET_NR_fork1		143	/* undefined for Solaris 10 */
#define	TARGET_NR_sigtimedwait	144
#define	TARGET_NR_lwp_info	145
#define	TARGET_NR_yield		146
#define	TARGET_NR_lwp_sema_wait	147	/* undefined in Solaris 10 */
#define	TARGET_NR_lwp_sema_post	148
#define	TARGET_NR_lwp_sema_trywait 149
#define	TARGET_NR_lwp_detach	150	/* undefined for Solaris 7 */
#define	TARGET_NR_corectl	151
#define	TARGET_NR_modctl	152
#define	TARGET_NR_fchroot	153
#define	TARGET_NR_utimes	154
#define	TARGET_NR_vhangup	155
#define	TARGET_NR_gettimeofday	156
#define	TARGET_NR_getitimer	157
#define	TARGET_NR_setitimer	158
#define	TARGET_NR_lwp_create	159
#define	TARGET_NR_lwp_exit	160
#define	TARGET_NR_lwp_suspend	161
#define	TARGET_NR_lwp_continue	162
#define	TARGET_NR_lwp_kill	163
#define	TARGET_NR_lwp_self	164
#define	TARGET_NR_lwp_setprivate 165	/* lwp_sigmask for Solaris 10 */
#define	TARGET_NR_lwp_getprivate 166	/* lwp_private for Solaris 10 */
#define	TARGET_NR_lwp_wait	167
#define	TARGET_NR_lwp_mutex_wakeup 168
#define	TARGET_NR_lwp_mutex_lock 169	/* undefined in Solaris 10 */
#define	TARGET_NR_lwp_cond_wait	170
#define	TARGET_NR_lwp_cond_signal 171
#define	TARGET_NR_lwp_cond_broadcast 172
#define	TARGET_NR_pread		173
#define	TARGET_NR_pwrite	174
#define	TARGET_NR__llseek	175
#define	TARGET_NR_inst_sync	176
#define	TARGET_NR_brand		177
#define	TARGET_NR_kaio		178
#define	TARGET_NR_cpc		179	/* undefined in Solaris 7 */
#define	TARGET_NR_meminfosys	180	/* undefined in Solaris 7 */
#define	TARGET_NR_rusagesys	181	/* undefined in Solaris 7 */
#define	TARGET_NR_port		182	/* undefined in Solaris 7 */
#define	TARGET_NR_pollsys	183	/* undefined in Solaris 7 */
#define	TARGET_NR_tsolsys	184	/* labelsys in Solaris 10 */
#define	TARGET_NR_acl		185
#define	TARGET_NR_auditsys	186
#define	TARGET_NR_processor_bind 187
#define	TARGET_NR_processor_info 188
#define	TARGET_NR_p_online	189
#define	TARGET_NR_sigqueue	190
#define	TARGET_NR_clock_gettime	191
#define	TARGET_NR_clock_settime	192
#define	TARGET_NR_clock_getres	193
#define	TARGET_NR_timer_create	194
#define	TARGET_NR_timer_delete	195
#define	TARGET_NR_timer_settime	196
#define	TARGET_NR_timer_gettime	197
#define	TARGET_NR_timer_getoverrun 198
#define	TARGET_NR_nanosleep	199
#define	TARGET_NR_facl		200
#define	TARGET_NR_door		201
#define	TARGET_NR_setreuid	202
#define	TARGET_NR_setregid	203
#define	TARGET_NR_install_utrap	204
#define	TARGET_NR_signotify	205
#define	TARGET_NR_schedctl	206
#define	TARGET_NR_pset		207
#define	TARGET_NR_sparc_utrap_install 208
#define	TARGET_NR_resolvepath	209
#define	TARGET_NR_signotifywait	210	/* lwp_mutex_timedlock for Solaris 10 */
#define	TARGET_NR_lwp_sigredirect 211	/* lwp_sema_timedwait for Solaris 10 */
#define	TARGET_NR_lwp_alarm	212	/* lwp_rwlock_sys for Solaris 10 */
/* system calls for large files ( > 2 gigabyte) */
#define	TARGET_NR_getdents64	213
#define	TARGET_NR_mmap64	214
#define	TARGET_NR_stat64	215
#define	TARGET_NR_lstat64	216
#define	TARGET_NR_fstat64	217
#define	TARGET_NR_statvfs64	218
#define	TARGET_NR_fstatvfs64	219
#define	TARGET_NR_setrlimit64	220
#define	TARGET_NR_getrlimit64	221
#define	TARGET_NR_pread64	222
#define	TARGET_NR_pwrite64	223
#define	TARGET_NR_creat64	224
#define	TARGET_NR_open64	225
#define	TARGET_NR_rpcsys	226
#define	TARGET_NR_zone		227	/* undefined in Solaris 7 */
#define	TARGET_NR_autofssys	228	/* undefined in Solaris 7 */
#define	TARGET_NR_getcwd	229
#define	TARGET_NR_so_socket	230
#define	TARGET_NR_so_socketpair	231
#define	TARGET_NR_bind		232
#define	TARGET_NR_listen	233
#define	TARGET_NR_accept	234
#define	TARGET_NR_connect	235
#define	TARGET_NR_shutdown	236
#define	TARGET_NR_recv		237
#define	TARGET_NR_recvfrom	238
#define	TARGET_NR_recvmsg	239
#define	TARGET_NR_send		240
#define	TARGET_NR_sendmsg	241
#define	TARGET_NR_sendto	242
#define	TARGET_NR_getpeername	243
#define	TARGET_NR_getsockname	244
#define	TARGET_NR_getsockopt	245
#define	TARGET_NR_setsockopt	246
#define	TARGET_NR_sockconfig	247
/* NTP system calls */
#define	TARGET_NR_ntp_gettime	248
#define	TARGET_NR_ntp_adjtime	249
#define	TARGET_NR_lwp_mutex_unlock 250
#define	TARGET_NR_lwp_mutex_trylock 251
#define	TARGET_NR_lwp_mutex_register 252
#define	TARGET_NR_cladm		253
#define	TARGET_NR_uucopy	254	/* undefined in Solaris 7 */
#define	TARGET_NR_umount2	255	/* undefined in Solaris 7 */


/* forksys(cmd) */
#define TARGET_NR_forksys_forkx		0
#define TARGET_NR_forksys_forkallx	1
#define TARGET_NR_forksys_vforkx	2

/* pgrpsys(cmd, ...) */
#define TARGET_NR_pgrpsys_getpgrp	0
#define TARGET_NR_pgrpsys_setpgrp	1
#define TARGET_NR_pgrpsys_getsid	2
#define TARGET_NR_pgrpsys_setsid	3
#define TARGET_NR_pgrpsys_getpgid	4
#define TARGET_NR_pgrpsys_setpgid	5

/* sigpendingsys(cmd, ...) */
#define TARGET_NR_sigpsys_sigpending	1
#define TARGET_NR_sigpsys_sigfillset	2

/* memcntl(..., ..., cmd, ...) */
#define TARGET_NR_memcntl_msync		1
#define TARGET_NR_memcntl_mlock		2
#define TARGET_NR_memcntl_munlock	3
#define TARGET_NR_memcntl_madvise	4
#define TARGET_NR_memcntl_mlockall	5
#define TARGET_NR_memcntl_munlockall	6
#define TARGET_NR_memcntl_hatadvise	7

/* context(cmd, ...) */
#define TARGET_NR_context_getcontext	0
#define TARGET_NR_context_setcontext	1

/* fsat(cmd, ...) */
#define TARGET_NR_fsat_openat		0
#define TARGET_NR_fsat_openat64		1
#define TARGET_NR_fsat_fstatat64	2
#define TARGET_NR_fsat_fstatat		3
#define TARGET_NR_fsat_renameat		4
#define TARGET_NR_fsat_fchownat		5
#define TARGET_NR_fsat_unlinkat		6
#define TARGET_NR_fsat_futimesat	7

/* msgsys(cmd, ...) */
#define TARGET_NR_msgsys_msgget		0
#define TARGET_NR_msgsys_msgctl		1
#define TARGET_NR_msgsys_msgrcv		2
#define TARGET_NR_msgsys_msgsnd		3
#define TARGET_NR_msgsys_msgids		4
#define TARGET_NR_msgsys_msgsnap	5

/* shmsys(cmd, ...) */
#define TARGET_NR_shmsys_shmat		0
#define TARGET_NR_shmsys_shmctl		1
#define TARGET_NR_shmsys_shmdt		2
#define TARGET_NR_shmsys_shmget		3
#define TARGET_NR_shmsys_shmids		4

/* semsys(cmd, ...) */
#define TARGET_NR_semsys_semctl		0
#define TARGET_NR_semsys_semget		1
#define TARGET_NR_semsys_semop		2
#define TARGET_NR_semsys_semids		3
#define TARGET_NR_semsys_semtimedop	4

/* rusagesys(cmd, ...) */
#define TARGET_NR_rusagesys_rusage	0
#define TARGET_NR_rusagesys_rusagecld	1
#define TARGET_NR_rusagesys_rusagelwp	2
#define TARGET_NR_rusagesys_vmusage	3

/* sysconfig(cmd) */
#define TARGET_NR_sysconf_childmax	3
#define TARGET_NR_sysconf_openmax	4
#define TARGET_NR_sysconf_pagesize	6
#define TARGET_NR_sysconf_clktick	7
#define TARGET_NR_sysconf_nprocs	12
#define TARGET_NR_sysconf_physmem	26
#define TARGET_NR_sysconf_stckprot	43

/* systnfosunos(cmd, ...) */
#define TARGET_NR_sysinfo_gethostname	2
#define TARGET_NR_sysinfo_sethostname	258
#define TARGET_NR_sysinfo_getsrpcdomain	9
#define TARGET_NR_sysinfo_setsrpcdomain	265
#define TARGET_NR_sysinfo_sysname	1
#define TARGET_NR_sysinfo_release	3
#define TARGET_NR_sysinfo_version	4
#define TARGET_NR_sysinfo_machine	5
#define TARGET_NR_sysinfo_cpuarch	6
#define TARGET_NR_sysinfo_hwserial	7
#define TARGET_NR_sysinfo_hwproducer	8
#define TARGET_NR_sysinfo_platform	513
#define TARGET_NR_sysinfo_isalist	514
#define TARGET_NR_sysinfo_arch32	516
#define TARGET_NR_sysinfo_arch64	517
#define TARGET_NR_sysinfo_archkern	518
#define TARGET_NR_sysinfo_archnative	519
