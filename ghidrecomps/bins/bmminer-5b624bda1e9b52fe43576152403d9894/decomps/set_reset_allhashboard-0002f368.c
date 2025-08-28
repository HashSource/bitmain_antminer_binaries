
/* WARNING: Unknown calling convention */

void set_reset_allhashboard(int resetBit)

{
  uint uVar1;
  char logstr [256];
  
  if (resetBit < 1) {
    uVar1 = axi_fpga_addr[0xd] >> 0x10;
  }
  else {
    uVar1 = ~(axi_fpga_addr[0xd] >> 0x10);
  }
  if (resetBit < 1) {
    uVar1 = uVar1 << 0x10;
  }
  else {
    uVar1 = ~(uVar1 << 0x10);
  }
  sprintf(logstr,"set_reset_allhashboard = 0x%08x\n",uVar1);
  writeInitLogFile(logstr);
  axi_fpga_addr[0xd] = uVar1;
  return;
}

