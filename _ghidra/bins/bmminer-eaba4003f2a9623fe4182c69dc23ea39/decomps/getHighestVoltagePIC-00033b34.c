
uchar getHighestVoltagePIC(int chainIndex)

{
  int iVar1;
  uint uVar2;
  int chainIndex_local;
  int startIndex;
  uchar minVolPIC;
  int i;
  
  if ((fpga_version < 0xe) && (fpga_major_version < 0xc6)) {
    minVolPIC = chain_voltage_pic[chainIndex];
    iVar1 = (chainIndex / 3) * 3;
    for (i = iVar1; i < iVar1 + 3; i = i + 1) {
      if (chain_voltage_pic[i] < minVolPIC) {
        minVolPIC = chain_voltage_pic[i];
      }
    }
    return minVolPIC;
  }
  if ((uint)chainIndex < 0xe) {
    uVar2 = 1 << (chainIndex & 0xffU);
    if ((uVar2 & 0x3008) != 0) {
      minVolPIC = chain_voltage_pic[3];
      for (i = 0xc; i < 0xe; i = i + 1) {
        if (chain_voltage_pic[i] < minVolPIC) {
          minVolPIC = chain_voltage_pic[i];
        }
      }
      return minVolPIC;
    }
    if ((uVar2 & 0xc04) != 0) {
      minVolPIC = chain_voltage_pic[2];
      for (i = 10; i < 0xc; i = i + 1) {
        if (chain_voltage_pic[i] < minVolPIC) {
          minVolPIC = chain_voltage_pic[i];
        }
      }
      return minVolPIC;
    }
    if ((uVar2 & 0x302) != 0) {
      minVolPIC = chain_voltage_pic[1];
      for (i = 8; i < 10; i = i + 1) {
        if (chain_voltage_pic[i] < minVolPIC) {
          minVolPIC = chain_voltage_pic[i];
        }
      }
      return minVolPIC;
    }
  }
  return '\0';
}

