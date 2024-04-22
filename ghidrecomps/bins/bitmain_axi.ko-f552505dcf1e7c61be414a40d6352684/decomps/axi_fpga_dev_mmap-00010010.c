
int axi_fpga_dev_mmap(undefined4 param_1,int *param_2,undefined4 param_3)

{
  int iVar1;
  uint uVar2;
  
  uVar2 = param_2[9];
  param_2[9] = uVar2 & 0xffffffc3;
  param_2[10] = param_2[10] | 0x4044000;
  iVar1 = remap_pfn_range(param_2,*param_2,0x40000,param_2[1] - *param_2,uVar2 & 0xffffffc3,param_2,
                          param_3);
  if (iVar1 != 0) {
    printk(DAT_00010064);
    iVar1 = -0xb;
  }
  return iVar1;
}

