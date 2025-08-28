
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int init_module(undefined4 param_1,undefined4 param_2)

{
  undefined4 uVar1;
  int iVar2;
  
  printk("In fpga mem driver!\n");
  iVar2 = alloc_chrdev_region(&fpga_mem_num,0,1,"fpga_mem",param_1,param_2);
  if (iVar2 < 0) {
    printk("alloc fpga_mem fail!\n");
  }
  else {
    p_fpga_mem = kmem_cache_alloc(_DAT_00011064,0x24000c0);
    if (p_fpga_mem == 0) {
      printk("kmalloc cdev fail!\n");
      iVar2 = -10;
    }
    else {
      cdev_init(p_fpga_mem,&fpga_mem_fops);
      iVar2 = p_fpga_mem;
      uVar1 = fpga_mem_num;
      *(undefined1 **)(p_fpga_mem + 0x24) = &__this_module;
      iVar2 = cdev_add(iVar2,uVar1,1);
      if (iVar2 == 0) {
        base_vir_mem_addr =
             __request_region(&iomem_resource,fpga_mem_offset_addr,0x1000000,"fpga_vir_mem",0);
        if (base_vir_mem_addr == 0) {
          printk("request_mem_region failed!\n");
          iVar2 = -0xc;
        }
        else {
          printk("request_mem_region OK!\n");
          base_vir_addr = ioremap(fpga_mem_offset_addr,0x1000000);
          if (base_vir_addr == 0) {
            printk("ioremap fail!\n",0);
            printk("!!!*base_vir_addr = 0x%x\n",base_vir_addr);
            iVar2 = -0xd;
          }
          else {
            printk("fpga mem virtual address is 0x%x\n",base_vir_addr);
            fpga_mem_class = __class_create(&__this_module,"fpga_mem",&fpga_mem_class);
            if (fpga_mem_class < 0xfffff001) {
              device_create(fpga_mem_class,0,fpga_mem_num,0,"fpga_mem");
              iVar2 = 0;
            }
            else {
              printk("Err:failed in creating fpga mem class.\n");
              iVar2 = -0xe;
            }
          }
        }
      }
      else {
        printk("add fpga_mem fail!\n");
        iVar2 = -0xb;
      }
    }
  }
  return iVar2;
}

