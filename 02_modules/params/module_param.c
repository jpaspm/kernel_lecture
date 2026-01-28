#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/moduleparam.h>

MODULE_LICENSE("GPL");

static char *name = "world";
static int count = 1;
static int arr_params[3] = {0, 0, 0};
static int arr_argc = 0;

/* 
 * module_param(name, type, perm)
 * perm is permission bits (e.g., S_IRUGO for read-only to user)
 */
module_param(name, charp, S_IRUGO);
MODULE_PARM_DESC(name, "The name to display in printk");

module_param(count, int, S_IRUGO);
MODULE_PARM_DESC(count, "Number of times to print");

module_param_array(arr_params, int, &arr_argc, S_IRUGO);
MODULE_PARM_DESC(arr_params, "An array of integers");

static int __init param_init(void) {
    int i;
    printk(KERN_INFO "Module Parameters: Name is %s\n", name);
    for (i = 0; i < count; i++) {
        printk(KERN_INFO "(%d) Hello %s\n", i + 1, name);
    }
    
    printk(KERN_INFO "Array parameters provided: %d\n", arr_argc);
    for(i = 0; i < arr_argc; i++) {
        printk(KERN_INFO "arr_params[%d] = %d\n", i, arr_params[i]);
    }
    
    return 0;
}

static void __exit param_exit(void) {
    printk(KERN_INFO "Module Unloaded\n");
}

module_init(param_init);
module_exit(param_exit);
