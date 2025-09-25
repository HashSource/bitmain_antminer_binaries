
ulong bn_div_words(ulong h,ulong l,ulong d)

{
  int iVar1;
  ulong uVar2;
  int iVar3;
  int iVar4;
  
  if (d == 0) {
    return 0xffffffff;
  }
  iVar1 = BN_num_bits_word(d);
  iVar4 = d << (0x40U - iVar1 & 0xff);
  iVar1 = -iVar4;
  iVar3 = iVar1;
  if (iVar1 == 0) {
    return 0xffffffff;
  }
  do {
    iVar3 = iVar3 - iVar4;
  } while (iVar3 != 0);
  uVar2 = 0xffffffff;
  do {
    iVar1 = iVar1 - iVar4;
    uVar2 = uVar2 - 1;
  } while (iVar1 != 0);
  return uVar2;
}

