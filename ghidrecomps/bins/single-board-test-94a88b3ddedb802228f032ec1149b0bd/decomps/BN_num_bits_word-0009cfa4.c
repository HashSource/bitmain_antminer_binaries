
int BN_num_bits_word(ulong param_1)

{
  int iVar1;
  uint uVar2;
  
  if (param_1 >> 0x10 == 0) {
    if ((param_1 & 0xff00) == 0) {
      uVar2 = (uint)*(byte *)(DAT_0009cfdc + param_1 + 0x14);
    }
    else {
      uVar2 = *(byte *)(DAT_0009cfdc + (param_1 >> 8) + 0x14) + 8;
    }
    return uVar2;
  }
  if ((param_1 & 0xff000000) == 0) {
    iVar1 = *(byte *)(DAT_0009cfdc + (param_1 >> 0x10) + 0x14) + 0x10;
  }
  else {
    iVar1 = *(byte *)(DAT_0009cfdc + (param_1 >> 0x18) + 0x14) + 0x18;
  }
  return iVar1;
}

