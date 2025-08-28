
/* WARNING: Unknown calling convention */

uchar getHighestVoltagePIC(int chainIndex)

{
  int iVar1;
  byte bVar2;
  uint uVar3;
  
  if (fpga_version < 0xe) {
    iVar1 = (chainIndex / 3) * 3;
    bVar2 = chain_voltage_pic[iVar1];
    if (chain_voltage_pic[chainIndex] <= chain_voltage_pic[iVar1]) {
      bVar2 = chain_voltage_pic[chainIndex];
    }
    if (chain_voltage_pic[iVar1 + 1] <= bVar2) {
      bVar2 = chain_voltage_pic[iVar1 + 1];
    }
    if (chain_voltage_pic[iVar1 + 2] <= bVar2) {
      bVar2 = chain_voltage_pic[iVar1 + 2];
    }
    return bVar2;
  }
  if ((uint)chainIndex < 0xe) {
    uVar3 = 1 << (chainIndex & 0xffU);
    if ((uVar3 & 0x3008) != 0) {
      bVar2 = chain_voltage_pic[0xc];
      if (chain_voltage_pic[3] <= chain_voltage_pic[0xc]) {
        bVar2 = chain_voltage_pic[3];
      }
      if (chain_voltage_pic[0xd] <= bVar2) {
        bVar2 = chain_voltage_pic[0xd];
      }
      return bVar2;
    }
    if ((uVar3 & 0xc04) != 0) {
      bVar2 = chain_voltage_pic[10];
      if (chain_voltage_pic[2] <= chain_voltage_pic[10]) {
        bVar2 = chain_voltage_pic[2];
      }
      if (chain_voltage_pic[0xb] <= bVar2) {
        bVar2 = chain_voltage_pic[0xb];
      }
      return bVar2;
    }
    if ((uVar3 & 0x302) != 0) {
      bVar2 = chain_voltage_pic[8];
      if (chain_voltage_pic[1] <= chain_voltage_pic[8]) {
        bVar2 = chain_voltage_pic[1];
      }
      if (chain_voltage_pic[9] <= bVar2) {
        bVar2 = chain_voltage_pic[9];
      }
      return bVar2;
    }
  }
  return '\0';
}

