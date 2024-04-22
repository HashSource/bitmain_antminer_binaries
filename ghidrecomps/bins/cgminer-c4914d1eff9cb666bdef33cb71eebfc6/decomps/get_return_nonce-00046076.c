
int get_return_nonce(uint *buf)

{
  uint uVar1;
  uint *buf_local;
  int ret;
  
  *buf = axi_fpga_addr[4];
  uVar1 = axi_fpga_addr[5];
  buf[1] = uVar1;
  return uVar1;
}

