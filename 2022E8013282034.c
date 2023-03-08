#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/slab.h>
#include <linux/vmalloc.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("haoranx98");
MODULE_DESCRIPTION("A simple example of kmalloc.");
MODULE_VERSION("0.01");

static int __init kmalloc_InitFunc(void);
static void __exit kmalloc_ExitFunc(void);

#define MEMORY_1KB 1024
#define MEMORY_8KB 8192

char *app_1KB_memory;
char *app_8KB_memory;

int __init kmalloc_InitFunc(void){
	
	app_1KB_memory = (char *)kmalloc(MEMORY_1KB, GFP_KERNEL);
	if(app_1KB_memory == NULL){
		printk("Can not apply memory!!!!\n");
	}else{
		printk("1KB address is 0x%1x\n", (unsigned long)app_1KB_memory);
	}
	app_8KB_memory = (char *)kmalloc(MEMORY_8KB, GFP_KERNEL);
	if(app_8KB_memory == NULL){
		printk("Can not apply memory!!!!\n");
	}else{
		printk("8KB address is 0x%1x\n", (unsigned long)app_8KB_memory);
	}

	return 0;
}

void __exit kmalloc_ExitFunc(void){
	if(app_1KB_memory != NULL){
		kfree(app_1KB_memory);
		printk("free the kernel memory of 1KB");
	}

	if(app_8KB_memory != NULL){
		kfree(app_8KB_memory);
		printk("free the kernel memory of 8KB");
	}

	printk("Exit kernel module!!!!");
}

module_init(kmalloc_InitFunc);
module_exit(kmalloc_ExitFunc);


