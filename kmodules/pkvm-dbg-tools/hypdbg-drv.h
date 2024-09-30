#ifndef __HYP_DBG__
#define __HYP_DBG__


#define HYP_DBG_CALL_INIT		0x0
#define HYP_DBG_CALL_DEINIT		0x1
#define HYP_DBG_CALL_READ_BUFFER	0x2

#define HYP_DBG_CALL_PRINT_S2 		0x11
#define HYP_DBG_CALL_COUNT_SHARED	0x12

struct ioctl_params {
    u32 dlen;
    u32 id;
    u64 addr;
    u64 size;
    u8  lock;
    u8  dump;
};

struct shared_buf {
	u32 size;
	u32 ri;
	u32 wi;
	u8 data[];
};

#define IOCTL_PRINT_S2_MAPPING		1
#define IOCTL_COUNT_SHARED		2
#define IOCTL_RAMLOG			3

#define MAGIC 0xDE
#define HYPDBG_COUNT_SHARED_S2_MAPPING 	\
	_IOW(MAGIC, IOCTL_COUNT_SHARED, struct ioctl_params)
#define HYPDBG_PRINT_S2_MAPPING  \
	_IOW(MAGIC, IOCTL_PRINT_S2_MAPPING, struct ioctl_params)
#define HYPDBG_PRINT_RAMLOG \
		_IOWR(MAGIC, IOCTL_RAMLOG, struct ioctl_params)
#endif // __HYP_DRV__
