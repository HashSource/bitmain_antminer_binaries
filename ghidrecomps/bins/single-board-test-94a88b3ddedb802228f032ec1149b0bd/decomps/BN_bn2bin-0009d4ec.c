
int BN_bn2bin(BIGNUM *a,uchar *to)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  ulong *puVar4;
  uint uVar5;
  
  iVar1 = a->top;
  if (iVar1 != 0) {
    puVar4 = a->d;
    uVar2 = puVar4[iVar1 + -1];
    if (uVar2 >> 0x10 == 0) {
      if ((uVar2 & 0xff00) == 0) {
        uVar2 = (uint)*(byte *)(DAT_0009d57c + uVar2 + 0x14);
      }
      else {
        uVar2 = *(byte *)(DAT_0009d57c + (uVar2 >> 8) + 0x14) + 8;
      }
    }
    else if ((uVar2 & 0xff000000) == 0) {
      uVar2 = *(byte *)(DAT_0009d57c + (uVar2 >> 0x10) + 0x14) + 0x10;
    }
    else {
      uVar2 = *(byte *)(DAT_0009d57c + (uVar2 >> 0x18) + 0x14) + 0x18;
    }
    iVar1 = (iVar1 + -1) * 0x20 + uVar2;
    iVar3 = iVar1 + 7;
    iVar1 = iVar1 + 0xe;
    if (-1 < iVar3) {
      iVar1 = iVar3;
    }
    iVar1 = iVar1 >> 3;
    uVar2 = iVar1 - 1;
    if (iVar1 != 0) {
      while( true ) {
        uVar5 = uVar2 + 3 & (int)uVar2 >> 0x20;
        if (uVar2 < 0xfffffffd) {
          uVar5 = uVar2;
        }
        *to = (uchar)(puVar4[(int)uVar5 >> 2] >> (((int)uVar2 % 4) * 8 & 0xffU));
        if (uVar2 - 1 == 0xffffffff) break;
        puVar4 = a->d;
        to = to + 1;
        uVar2 = uVar2 - 1;
      }
    }
  }
  return iVar1;
}

