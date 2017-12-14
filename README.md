# ARMpagetable
Linux kernel module that prints the page table

**This project is for didactic purpose**, the code is tested on a Raspberry Pi 3 and should be compatible with every ARMv6/ARMv7 device.

## Paging in ARM
l'architettura ARMv6/ARMv7 utilizza una page table a 2 livelli e supporta pagine di 4 dimensioni diverse:

1. **Supersections**: Blocchi di memoria da 16MB, (24 bit di offset)
2. **Sections**: Blocchi di memoria da 1MB, (20 bit di offset)
3. **Large Pages**: Blocchi di memoria da 64KB, (16 bit di offset)
4. **Small Pages**: Blocchi di memoria da 4KB, (12 bit di offset)



### Disable _ASLR_
In order to disable _ASLR_ create the file `/etc/sysctl.d/01-disable-aslr.conf` containing the following line: 
```
kernel.randomize_va_space = 0
```
