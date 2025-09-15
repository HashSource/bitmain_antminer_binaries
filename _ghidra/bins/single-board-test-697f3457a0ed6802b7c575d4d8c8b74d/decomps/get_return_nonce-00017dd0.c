
void get_return_nonce(uint *buf)

{
  uint uVar1;
  uint *buf_local;
  
  uVar1 = read_axi_fpga(4);
  *buf = uVar1;
  uVar1 = read_axi_fpga(5);
  buf[1] = uVar1;
  return;
}

