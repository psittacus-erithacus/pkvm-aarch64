/* SPDX-License-Identifier: #include "hyp_debug.h"
 * GPL-2.0-only */

#ifndef __MOD_ARM64_KVM_HYP_HYP_DEBUG_H__
#define __MOD_ARM64_KVM_HYP_HYP_DEBUG_H__
#include <asm/kvm_host.h>
#include <nvhe/dbg_tool_mod.h>

#define HYP_DBG_CALL_INIT		0x0
#define HYP_DBG_CALL_DEINIT		0x1
#define HYP_DBG_CALL_READ_BUFFER	0x2

#define HYP_DBG_CALL_COUNT_SHARED	0x11
#define HYP_DBG_CALL_PRINT_S2 		0x12


struct shared_buffer {
	u32 size;
	u32 ri;
	u32 wi;
	u8 data[];
};
extern struct shared_buffer *dbg_buffer;
extern struct dbg_tool_ops *dops;
extern const struct pkvm_module_ops *ops;

//int hyp_print(const char *fmt, ...);
int hyp_vsnprintf(char *str, size_t size, const char *format, va_list ap);
int hyp_snprint(char *s, size_t slen, const char *format, ...);
int hyp_dbg_print(const char *fmt, ...);
int hyp_print(const char *fmt, ...);

/**
 *gdb helper function on hypervisor. Jump to EL2 and waits
 *    on the spin lock until gdb is stopped.
 *
 *@param irrelevant for now
 *@return 0
 *
 */
#if 0
int attach_gdb(u64 param);

/**
 * do debug function on hypervisor
 *
 * @cmm function id to be executed
 * @param1 the 1st parameter of the function
 * @param2 the 2nd parameter of the function
 * @param3 the 3rd parameter of the function
 * @param4 the 4th parameter of the function
 *
 * @return retutn value of the function
 */
#endif
u64 hyp_dbg(u64 cmd, u64 param1, u64 param2, u64 param3, u64 param4);

/**
 * Print and count the amount of guest/hypervisor ram visible to the host
 *
 * @param handle guest to query. if 0 do query for hypervisor
 * @param size the size of query
 * @param lock make the pages read only for the guest
 * @return int count of shared pages or -errno
 */

u64 print_mappings(u32 id, u64 addr, u64 size, u64 cont);
/**
 * Initialise shared RAM for hyp-debuggergit
 *
 *  @param pfn the start page of shared memory
 *  @param size the size of the sharedf memory
 *  @return int count of shared pages or -errno
 */
int count_shared(u32 id, u64 size, u64 lock, u64 cont);

#endif
