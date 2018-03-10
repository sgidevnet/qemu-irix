#ifndef SPARC64_TARGET_SIGNAL_H
#define SPARC64_TARGET_SIGNAL_H

#include "cpu.h"

/* this struct defines a stack used during syscall handling */

typedef struct target_sigaltstack {
	abi_ulong ss_sp;
	abi_long ss_flags;
	abi_ulong ss_size;
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


#endif /* SPARC64_TARGET_SIGNAL_H */
