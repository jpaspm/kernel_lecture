#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>

MODULE_LICENSE("GPL");

/* Function to be exported */
int calculate_average(int a, int b) {
    return (a + b) / 2;
}

/* Macro to export the symbol to the kernel symbol table */
EXPORT_SYMBOL(calculate_average);

static int __init avg_init(void) {
    printk(KERN_INFO "Avg mod loaded: function calculate_average exported.\n");
    return 0;
}

static void __exit avg_exit(void) {
    printk(KERN_INFO "Avg mod unloaded.\n");
}

module_init(avg_init);
module_exit(avg_exit);
