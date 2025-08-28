
void cleanup_module(void)

{
  unregister_chrdev_region(axi_fpga_dev_num,1);
  cdev_del(p_axi_fpga_dev);
  kfree(p_axi_fpga_dev);
  iounmap(base_vir_addr);
  __release_region(&iomem_resource,0x40000000,0x1400);
  device_destroy(axi_fpga_class,axi_fpga_dev_num);
  class_destroy(axi_fpga_class);
  printk("Bye Bye axi fpga driver!\n");
  return;
}

