obj-m := hello.o # generates hello.ko from hello.o

KERNELDIR := /lib/modules/$(shell uname -r)/build/

PWD := $(shell pwd)

all:
	$(MAKE) -C $(KDIR) M=$(PWD) modules
	# -C change directory to read top-level makefile
	#  M= move bak to pwd before build
clean:
	$(MAKE) -C $(KDIR) M=$(PWD) clean
