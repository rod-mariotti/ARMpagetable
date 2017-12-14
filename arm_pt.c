#include <linux/module.h>
#include <linux/init.h>
#include <linux/sched.h>
#include <linux/mm.h>
#include <linux/mm_types.h>
#include <linux/kernel.h>

#define PRESENT_BIT ARM_PRESENT_BIT_MASK
#define PGB_SIZE ARM_PGB_SIZE

static int present_bit_isset(unsigned long int page_entry);
static void print_pgd(unsigned long int *page_glb_dir);

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

static int present_bit_isset(unsigned long int page_entry)
{
    return (page_entry && PRESENT_BIT);
}

static void print_pgd(unsigned long int *page_glb_dir)
{
    int i_page_glb_dir;
    
    printk(KERN_ALERT "==== PAGE GLOBAL DIRECTORY ====\n");
    
    for (i_page_glb_dir; i_page_glb_dir < PGB_SIZE; page_glb_dir++) {
        if (present_bit_isset(page_glb_dir[i_page_glb_dir])) {
            printk(KERN_ALERT "PGD index: %d\tPGD entry = 0x%16.16lx\n",
                   i_page_glb_dir,
                   (unsigned long int) page_glb_dir[i_page_glb_dir]);
        }
    }
}


MODULE_LICENSE("GPL");
MODULE_AUTHOR("Rodolfo Mariotti <rodolfo.mariotti@mail.polimi.it>");
MODULE_DESCRIPTION("Print page table");
MODULE_VERSION("0.0");
