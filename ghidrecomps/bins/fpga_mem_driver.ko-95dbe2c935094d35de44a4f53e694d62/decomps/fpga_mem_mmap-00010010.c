
int fpga_mem_mmap(undefined4 param_1,int *param_2,undefined4 param_3)

{
  int *piVar1;
  int iVar2;
  uint uVar3;
  
  uVar3 = param_2[9];
  param_2[10] = param_2[10] | 0x4044000;
  piVar1 = DAT_00010070;
  param_2[9] = uVar3 & 0xffffffc3;
  iVar2 = remap_pfn_range(param_2,*param_2,*piVar1 >> 0xc,param_2[1] - *param_2,uVar3 & 0xffffffc3,
                          param_2,param_3);
  if (iVar2 != 0) {
    printk(DAT_00010074);
    iVar2 = -9;
  }
  return iVar2;
}

