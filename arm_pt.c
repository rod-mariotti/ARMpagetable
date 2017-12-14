#include <linux/module.h>
#include <linux/init.h>
#include <linux/sched.h>
#include <linux/mm.h>
#include <linux/mm_types.h>
#include <linux/kernel.h>

#define PRESENT_BIT ARM_PRESENT_BIT_MASK
#define PGB_SIZE ARM_PGB_SIZE

static int present_isset(unsigned long int page_entry);
static void print_pgd(unsigned long int *pgd);

static int __init arm_pt_init(void)
{
    ;
}
module_init(arm_pt_init);

static void __exit arm_pt_exit(void)
{
    ;
}
module_exit(arm_pt_exit);

static int present_isset(unsigned long int page_entry)
{
    return (page_entry & PRESENT_BIT);
}

static void print_pgd(unsigned long int *pgd)
{
    int i_pgd;
    
    printk(KERN_ALERT "==== PAGE GLOBAL DIRECTORY ====\n");
    
    for (i_pgd; i_pgd < PGB_SIZE; i_pgd++) {
        if (present_isset(pgd[i_pgd])) {
            printk(KERN_ALERT "PGD index: %d\tPGD entry = 0x%16.16lx\n", i_pgd,
                  (unsigned long int) pgd[i_page_glb_dir]);
        }
    }
}


MODULE_LICENSE("GPL");
MODULE_AUTHOR("Rodolfo Mariotti <rodolfo.mariotti@mail.polimi.it>");
MODULE_DESCRIPTION("Print page table");
MODULE_VERSION("0.0");
