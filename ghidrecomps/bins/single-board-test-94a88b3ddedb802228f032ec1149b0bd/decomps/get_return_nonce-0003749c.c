
undefined4 get_return_nonce(undefined4 *param_1)

{
  undefined4 uVar1;
  
  *param_1 = *(undefined4 *)(axi_fpga_addr + 0x10);
  uVar1 = *(undefined4 *)(axi_fpga_addr + 0x14);
  param_1[1] = uVar1;
  return uVar1;
}

