
int BN_num_bits(BIGNUM *a)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  
  if (a->top == 0) {
    return 0;
  }
  iVar3 = a->top + -1;
  iVar1 = iVar3 * 0x20;
  uVar2 = a->d[iVar3];
  if (uVar2 >> 0x10 != 0) {
    if ((uVar2 & 0xff000000) == 0) {
      iVar3 = *(byte *)(DAT_0009d030 + (uVar2 >> 0x10) + 0x14) + 0x10;
    }
    else {
      iVar3 = *(byte *)(DAT_0009d030 + (uVar2 >> 0x18) + 0x14) + 0x18;
    }
    return iVar1 + iVar3;
  }
  if ((uVar2 & 0xff00) == 0) {
    uVar2 = (uint)*(byte *)(DAT_0009d030 + uVar2 + 0x14);
  }
  else {
    uVar2 = *(byte *)(DAT_0009d030 + (uVar2 >> 8) + 0x14) + 8;
  }
  return iVar1 + uVar2;
}

