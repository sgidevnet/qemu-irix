#ifndef SOLARIS_TARGET_SIGNAL_H
#define SOLARIS_TARGET_SIGNAL_H

#include "cpu.h"

/* this struct defines a stack used during syscall handling */

typedef struct target_sigaltstack {
	abi_ulong ss_sp;
	abi_ulong ss_size;
	abi_long ss_flags;
} target_stack_t;


/*
 * sigaltstack controls
 */
#define TARGET_SS_ONSTACK	1
#define TARGET_SS_DISABLE	2

#define TARGET_MINSIGSTKSZ	4096
#define TARGET_SIGSTKSZ		16384

#ifndef UREG_O6
#define UREG_O6        6
#endif
#ifndef UREG_SP
#define UREG_SP        UREG_O6
#endif

static inline abi_ulong get_sp_from_cpustate(CPUSPARCState *state)
{
    return state->regwptr[UREG_SP];
}

struct target_mcontext32 {
        uint32_t gregs[19];
	uint32_t gwins;
        union {
            double dregs[16];
            float fregs[32];
        };
        uint32_t fqu;                  /* ptr to array of FQ entries */
        uint32_t fpfsr;                /* FPU status register */
        uint8_t fpqcnt;               /* # of entries in saved FQ */
        uint8_t fpqesz;        /* # of bytes per FQ entry */
        uint8_t fpen;                 /* flag signifying fpu in use */
        uint32_t pad1;
        uint32_t xrsid;
        uint32_t xrsptr;
        uint32_t pad[19];
};

struct target_mcontext64 {
        uint64_t gregs[21];
	uint32_t gwins;
        union {
            double dregs[16];
            float fregs[32];
        };
        uint32_t fqu;                  /* ptr to array of FQ entries */
        uint32_t fpfsr;                /* FPU status register */
        uint8_t fpqcnt;               /* # of entries in saved FQ */
        uint8_t fpqesz;        /* # of bytes per FQ entry */
        uint8_t fpen;                 /* flag signifying fpu in use */
        uint32_t pad1;
        uint32_t xrsid;
        uint32_t xrsptr;
        uint32_t pad[19];
};

struct target_mcontext {
        union {
	    struct target_mcontext32 _32;
	    struct target_mcontext64 _64;
	};
};

struct target_ucontext {
        abi_ulong           tuc_flags;
        abi_ulong           tuc_link;
        target_sigset_t     tuc_sigmask;
        struct target_sigaltstack  tuc_stack;
        int pad;
        struct target_mcontext tuc_mcontext;
};

int save_context(CPUSPARCState *regs, struct target_mcontext *sc, int setret);
int restore_context(CPUSPARCState *regs, struct target_mcontext *sc);

#endif /* TARGET_SIGNAL_H */
