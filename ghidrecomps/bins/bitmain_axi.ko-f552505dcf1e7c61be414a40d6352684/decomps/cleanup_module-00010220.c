
void cleanup_module(void)

{
  undefined4 *puVar1;
  
  puVar1 = DAT_0001027c;
  unregister_chrdev_region(*DAT_0001027c,1);
  cdev_del(puVar1[1]);
  kfree(puVar1[1]);
  iounmap(puVar1[3]);
  __release_region(DAT_00010280,0x40000000,0x1400);
  device_destroy(puVar1[4],*puVar1);
  class_destroy(puVar1[4]);
  printk(DAT_00010284);
  return;
}

