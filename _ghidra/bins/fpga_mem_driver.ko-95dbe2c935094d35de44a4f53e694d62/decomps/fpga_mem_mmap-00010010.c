
int fpga_mem_mmap(undefined4 param_1,int *param_2,undefined4 param_3)

{
  int iVar1;
  uint uVar2;
  
  uVar2 = param_2[9];
  param_2[10] = param_2[10] | 0x4044000;
  param_2[9] = uVar2 & 0xffffffc3;
  iVar1 = remap_pfn_range(param_2,*param_2,fpga_mem_offset_addr >> 0xc,param_2[1] - *param_2,
                          uVar2 & 0xffffffc3,param_2,param_3);
  if (iVar1 != 0) {
    printk("fpga_mem_mmap error!\n");
    iVar1 = -9;
  }
  return iVar1;
}

