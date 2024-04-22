
/* WARNING: Unknown calling convention */

int get_return_nonce(uint *buf)

{
  uint *puVar1;
  uint uVar2;
  
  puVar1 = axi_fpga_addr;
  *buf = axi_fpga_addr[4];
  uVar2 = puVar1[5];
  buf[1] = uVar2;
  return uVar2;
}

