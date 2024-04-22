
void cleanup_module(void)

{
  undefined4 *puVar1;
  
  puVar1 = DAT_00010290;
  unregister_chrdev_region(*DAT_00010290,1);
  cdev_del(puVar1[1]);
  kfree(puVar1[1]);
  iounmap(puVar1[3]);
  __release_region(DAT_00010298,*DAT_00010294,0x1000000);
  device_destroy(puVar1[4],*puVar1);
  class_destroy(puVar1[4]);
  printk(DAT_0001029c);
  return;
}

