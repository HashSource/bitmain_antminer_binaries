
int BN_bn2bin(BIGNUM *a,uchar *to)

{
  int iVar1;
  int iVar2;
  byte *pbVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  size_t len;
  uint uVar8;
  
  iVar2 = BN_num_bits(a);
  iVar5 = iVar2 + 7;
  if (iVar2 + 7 < 0) {
    iVar5 = iVar2 + 0xe;
  }
  len = iVar5 >> 3;
  iVar5 = a->dmax * 8;
  if (iVar5 != 0) {
    iVar2 = a->top;
    pbVar3 = to + len;
    if (len != 0) {
      iVar7 = iVar2 * -8;
      uVar4 = 0;
      do {
        uVar8 = uVar4 >> 3;
        uVar6 = uVar4 & 7;
        uVar4 = uVar4 - ((int)(uVar4 - (iVar5 + -1)) >> 0x1f);
        iVar1 = iVar7 >> 0x1f;
        iVar7 = iVar7 + 1;
        pbVar3 = pbVar3 + -1;
        *pbVar3 = (byte)(a->d[uVar8] >> (uVar6 << 3)) & (byte)iVar1;
      } while (len + iVar2 * -8 != iVar7);
    }
    return len;
  }
  OPENSSL_cleanse(to,len);
  return len;
}

