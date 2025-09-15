
/* WARNING: Unknown calling convention */

int getFixedFreqVoltageValue(int freq)

{
  int iVar1;
  
  if (0x289 < freq) {
    return 0x32a;
  }
  if (0x270 < freq) {
    return 0x33e;
  }
  if (599 < freq) {
    return 0x352;
  }
  if (freq < 0x23f) {
    if (freq < 0x21f) {
      iVar1 = 0x3a2;
      if (0x203 < freq) {
        iVar1 = 0x398;
      }
      return iVar1;
    }
    return 0x37a;
  }
  return 0x366;
}

