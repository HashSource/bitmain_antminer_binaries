
undefined4 get_return_nonce(undefined4 *param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = axi_fpga_addr;
  *param_1 = *(undefined4 *)(axi_fpga_addr + 0x10);
  uVar2 = *(undefined4 *)(iVar1 + 0x14);
  param_1[1] = uVar2;
  return uVar2;
}

