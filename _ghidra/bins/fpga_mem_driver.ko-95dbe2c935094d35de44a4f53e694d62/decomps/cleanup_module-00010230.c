
void cleanup_module(void)

{
  unregister_chrdev_region(fpga_mem_num,1);
  cdev_del(p_fpga_mem);
  kfree(p_fpga_mem);
  iounmap(base_vir_addr);
  __release_region(&iomem_resource,fpga_mem_offset_addr,0x1000000);
  device_destroy(fpga_mem_class,fpga_mem_num);
  class_destroy(fpga_mem_class);
  printk("Bye Bye fpga mem driver!\n");
  return;
}

