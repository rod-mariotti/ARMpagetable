#include <linux/module.h>
#include <linux/init.h>

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

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Rodolfo Mariotti <rodolfo.mariotti@mail.polimi.it>");
MODULE_DESCRIPTION("Print page table");
MODULE_VERSION("0.0");
