#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>

MODULE_LICENSE("GPL");

/* Declaration of the external function */
extern int calculate_average(int, int);

static int __init calc_init(void) {
    int a = 10, b = 20;
    int avg = calculate_average(a, b); // Function from other module
    printk(KERN_INFO "Calc mod loaded: Average of %d and %d is %d\n", a, b, avg);
    return 0;
}

static void __exit calc_exit(void) {
    printk(KERN_INFO "Calc mod unloaded.\n");
}

module_init(calc_init);
module_exit(calc_exit);
