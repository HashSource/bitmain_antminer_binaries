
int EVP_DecodeBlock(uchar *t,uchar *f,int n)

{
  byte bVar1;
  byte bVar2;
  int iVar3;
  byte *pbVar4;
  uint uVar5;
  int iVar6;
  uchar *puVar7;
  uint uVar8;
  
  iVar3 = DAT_00103e9c;
  uVar8 = (uint)*(byte *)(DAT_00103e9c + (*f & 0x7f) + 0x44);
  uVar5 = uVar8;
  if (uVar8 == 0xe0) {
    if (0 < n) {
      pbVar4 = f + 1;
      do {
        f = pbVar4;
        n = n - 1;
        uVar5 = (uint)*(byte *)(DAT_00103e9c + (*f & 0x7f) + 0x44);
        if (uVar5 != 0xe0) goto LAB_00103dcc;
        pbVar4 = f + 1;
        uVar5 = uVar8;
      } while (n != 0);
    }
  }
  else {
LAB_00103dcc:
    if (3 < n) {
      while ((*(byte *)(DAT_00103e9c + (f[n - 1] & 0x7f) + 0x44) | 0x13) == 0xf3) {
        n = n - 1;
        if (n == 3) {
          return -1;
        }
      }
      if ((n & 3U) != 0) {
        return -1;
      }
      goto LAB_00103e0a;
    }
  }
  if ((n & 3U) != 0) {
    return -1;
  }
  if (n < 1) {
    return 0;
  }
LAB_00103e0a:
  iVar6 = 0;
  puVar7 = t;
  while( true ) {
    uVar8 = (uint)*(byte *)(iVar3 + (f[1] & 0x7f) + 0x44);
    bVar1 = *(byte *)(iVar3 + (f[2] & 0x7f) + 0x44);
    bVar2 = *(byte *)(iVar3 + (f[3] & 0x7f) + 0x44);
    if ((((uVar8 | uVar5) & 0x80) != 0) ||
       (uVar5 = (uint)bVar2 | uVar5 << 0x12 | uVar8 << 0xc, ((bVar2 | bVar1) & 0x80) != 0)) break;
    uVar8 = uVar5 | (uint)bVar1 << 6;
    t[iVar6] = (uchar)(uVar5 >> 0x10);
    iVar6 = iVar6 + 3;
    puVar7[2] = (uchar)uVar8;
    puVar7[1] = (uchar)(uVar8 >> 8);
    puVar7 = puVar7 + 3;
    if (t + ((n - 1U >> 2) + 1) * 3 == puVar7) {
      return iVar6;
    }
    f = f + 4;
    uVar5 = (uint)*(byte *)((*f & 0x7f) + iVar3 + 0x44);
  }
  return -1;
}

