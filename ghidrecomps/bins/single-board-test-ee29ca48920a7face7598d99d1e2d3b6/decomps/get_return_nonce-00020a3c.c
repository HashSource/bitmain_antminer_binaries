
void get_return_nonce(undefined4 *param_1)

{
  undefined4 uVar1;
  
  uVar1 = read_axi_fpga(4);
  *param_1 = uVar1;
  uVar1 = read_axi_fpga(5);
  param_1[1] = uVar1;
  return;
}

