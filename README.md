# ARMpagetable
Linux kernel module that prints the page table

**This project is for didactic purpose**, the code is tested on a Raspberry Pi 3 and should be compatible with every ARMv6/ARMv7 device.

### Disable _ASLR_
In order to disable _ASLR_ create the file `/etc/sysctl.d/01-disable-aslr.conf` containing the following line: 
```
kernel.randomize_va_space = 0
```
