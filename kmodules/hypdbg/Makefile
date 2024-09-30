ifeq ($(DEBUG),1)
export OPTS := -g -O1 -DDEBUG
endif

export CROSS_COMPILE=$(PWD)/../../buildtools/usr/bin/aarch64-linux-gnu-
export KDIR=$(PWD)/../../linux-host
export ARCH=arm64
obj-m += hypdbg-drv.o

all: hypdbg-drv.ko


hypdbg-drv.ko:
	make ARCH=arm64 CROSS_COMPILE=$(CROSS_COMPILE) -C $(KDIR) M=$(PWD) \
	"KCFLAGS=$(OPTS)" modules


clean:
	make ARCH=arm64 CROSS_COMPILE=$(CROSS_COMPILE) -C $(KDIR) M=$(PWD) clean
