
/* WARNING: Unknown calling convention */

void set_reset_hashboard(int chainIndex,int resetBit)

{
  uint uVar1;
  char logstr [256];
  
  uVar1 = 1 << (chainIndex & 0xffU);
  if (resetBit < 1) {
    uVar1 = axi_fpga_addr[0xd] & ~uVar1;
  }
  else {
    uVar1 = uVar1 | axi_fpga_addr[0xd];
  }
  sprintf(logstr,"set_reset_hashboard = 0x%08x\n",uVar1);
  writeInitLogFile(logstr);
  axi_fpga_addr[0xd] = uVar1;
  return;
}

