
export CROSS_COMPILE=$(PWD)/../../buildtools/usr/bin/aarch64-linux-gnu-
export KDIR=$(PWD)/../../linux-host
export ARCH=arm64

ifneq ($(KERNELRELEASE),)
clean-files := hyp/hyp.lds hyp/hyp-reloc.S

#obj-m := hyp_tst.o
#hyp_tst-y := el1.o hyp/kvm_nvhe.o
obj-m := pkvm-dbg-tools.o
pkvm-dbg-tools-y := main.o hyp/kvm_nvhe.o

$(obj)/hyp/kvm_nvhe.o: FORCE
	echo $(obj)
	$(Q)$(MAKE) $(build)=$(obj)/hyp $(obj)/hyp/kvm_nvhe.o
else
all:
	echo $(CROSS_COMPILE)
	make -C $(KDIR) M=$(PWD) modules
clean:
	make -C $(KDIR) M=$(PWD) clean
endif