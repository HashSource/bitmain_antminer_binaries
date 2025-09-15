
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int init_module(undefined4 param_1,undefined4 param_2)

{
  undefined4 uVar1;
  int iVar2;
  char *pcVar3;
  
  printk("In axi fpga driver!\n");
  iVar2 = alloc_chrdev_region(&axi_fpga_dev_num,0,1,"axi_fpga_dev",param_1,param_2);
  if (iVar2 < 0) {
    pcVar3 = "alloc axi_fpga_dev fail!\n";
LAB_000100e8:
    printk(pcVar3);
  }
  else {
    p_axi_fpga_dev = kmem_cache_alloc(_DAT_00011060,0x24000c0);
    if (p_axi_fpga_dev == 0) {
      pcVar3 = "kmalloc cdev fail!\n";
    }
    else {
      cdev_init(p_axi_fpga_dev,&axi_fpga_dev_fops);
      iVar2 = p_axi_fpga_dev;
      uVar1 = axi_fpga_dev_num;
      *(undefined1 **)(p_axi_fpga_dev + 0x24) = &__this_module;
      iVar2 = cdev_add(iVar2,uVar1,1);
      if (iVar2 != 0) {
        pcVar3 = "add axi_fpga_dev fail!\n";
        goto LAB_000100e8;
      }
      base_vir_mem_addr = __request_region(&iomem_resource,0x40000000,0x1400,"axi_fpga_vir_mem",0);
      if (base_vir_mem_addr != 0) {
        printk("request_mem_region OK!\n");
        base_vir_addr = (undefined4 *)ioremap(0x40000000,0x1400);
        if (base_vir_addr == (undefined4 *)0x0) {
          printk("ioremap fail!\n",0);
          printk("!!!*base_vir_addr = 0x%x\n",base_vir_addr);
        }
        else {
          printk("AXI fpga dev virtual address is 0x%x\n",base_vir_addr);
          DataSynchronizationBarrier(0xf);
          printk("*base_vir_addr = 0x%x\n",*base_vir_addr);
          axi_fpga_class = __class_create(&__this_module,"axi_fpga_dev",&axi_fpga_class);
          if (axi_fpga_class < 0xfffff001) {
            device_create(axi_fpga_class,0,axi_fpga_dev_num,0,"axi_fpga_dev");
            return 0;
          }
          printk("Err:failed in creating axi fpga class.\n");
        }
        return -1;
      }
      pcVar3 = "request_mem_region failed!\n";
      base_vir_mem_addr = 0;
    }
    printk(pcVar3);
    iVar2 = 1;
  }
  return iVar2;
}

