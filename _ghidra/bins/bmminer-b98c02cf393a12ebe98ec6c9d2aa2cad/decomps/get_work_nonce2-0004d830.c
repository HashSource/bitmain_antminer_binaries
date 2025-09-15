
undefined4 get_work_nonce2(undefined4 *param_1)

{
  uint uVar1;
  int iVar2;
  
  iVar2 = axi_fpga_addr;
  *param_1 = *(undefined4 *)(axi_fpga_addr + 0x108);
  uVar1 = log_level;
  param_1[1] = *(undefined4 *)(iVar2 + 0x10c);
  if (5 < uVar1) {
    get_work_nonce2_part_1();
  }
  return 0xffffffff;
}

