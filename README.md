# ARMpagetable
Linux kernel module that prints the page table

### Disabilitare l'_ASLR_
Per disabilitare permanentemente l'ASLR creare il file `/etc/sysctl.d/01-disable-aslr.conf` contenete:
```
kernel.randomize_va_space = 0
```
