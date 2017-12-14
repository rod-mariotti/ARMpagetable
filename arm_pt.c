#include <linux/module.h>
#include <linux/init.h>
#include <linux/sched.h>
#include <linux/mm.h>
#include <linux/mm_types.h>
#include <linux/kernel.h>

#define PRESENT_BIT ARM_PRESENT_BIT_MASK
#define PGB_SIZE 4096

struct saddr { // split addr struct
    int i_pgd;
    int i_pmd;
    int i_pt;
    int offset;
}

static int present_isset(unsigned long int page_entry);
static void print_pgd(unsigned long int * pgd);
static void ctsk_explore(void);
static void split_addr(unsigned long int phaddr, struct saddr split);

static int __init arm_pt_init(void)
{
    ctsk_explore();
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

static void print_pgd(unsigned long int * pgd)
{
    int i_pgd;
    
    printk(KERN_ALERT "==== PAGE GLOBAL DIRECTORY ====\n");
    
    for (i_pgd; i_pgd < PGB_SIZE; i_pgd++) {
        if (present_isset(pgd[i_pgd])) {
            printk(KERN_ALERT "PGD index: %d\tPGD entry = 0x%8.8lx\n", i_pgd,
                  (unsigned long int) pgd[i_page_glb_dir]);
        }
    }
}

static void ctsk_explore(void)
{
    struct task_struct * ctsk;
    struct mm_struct * mms;

    ctsk = get_current();
    printk(KERN ALERT "==== PID current process: %d\n ====", ctsk->pid);

    mms = ts->mm;

    pgd = (unsigned long int *) mms->pgd;
    print_pgd(pgd);
}

static void split_addr(unsigned long int phaddr, struct saddr split)
{
    unsigned long tmp;
    split.offset = tmp & OFFSET;
    tmp = tmp >> 12

}

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Rodolfo Mariotti <rodolfo.mariotti@mail.polimi.it>");
MODULE_DESCRIPTION("Print page table");
MODULE_VERSION("0.0");
