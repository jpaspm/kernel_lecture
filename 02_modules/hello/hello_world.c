#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Antigravity");
MODULE_DESCRIPTION("A simple Hello World LKM");
MODULE_VERSION("0.1");

static int __init hello_start(void) {
    printk(KERN_INFO "Hello world module loaded\n");
    return 0;
}

static void __exit hello_end(void) {
    printk(KERN_INFO "Hello world module unloaded\n");
}

module_init(hello_start);
module_exit(hello_end);
