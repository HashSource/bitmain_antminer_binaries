
int EVP_DecodeBlock(uchar *t,uchar *f,int n)

{
  byte *pbVar1;
  int iVar2;
  uchar *puVar3;
  uint uVar4;
  uint uVar5;
  
  uVar4 = (uint)(byte)data_ascii2bin[*f & 0x7f];
  uVar5 = uVar4;
  if (uVar4 == 0xe0) {
    if (0 < n) {
      pbVar1 = f + 1;
      do {
        f = pbVar1;
        n = n - 1;
        uVar5 = (uint)(byte)data_ascii2bin[*f & 0x7f];
        if ((byte)data_ascii2bin[*f & 0x7f] != 0xe0) goto LAB_001a03b8;
        pbVar1 = f + 1;
        uVar5 = uVar4;
      } while (n != 0);
    }
  }
  else {
LAB_001a03b8:
    if (3 < n) {
      while ((data_ascii2bin[f[n - 1] & 0x7f] | 0x13) == 0xf3) {
        n = n - 1;
        if (n == 3) {
          return -1;
        }
      }
      if ((n & 3U) != 0) {
        return -1;
      }
      goto LAB_001a03f6;
    }
  }
  if ((n & 3U) != 0) {
    return -1;
  }
  if (n < 1) {
    return 0;
  }
LAB_001a03f6:
  iVar2 = 0;
  puVar3 = t;
  while( true ) {
    if (((((byte)data_ascii2bin[f[1] & 0x7f] | uVar5) & 0x80) != 0) ||
       (uVar5 = (uint)(byte)data_ascii2bin[f[3] & 0x7f] | uVar5 << 0x12 |
                (uint)(byte)data_ascii2bin[f[1] & 0x7f] << 0xc,
       ((data_ascii2bin[f[3] & 0x7f] | data_ascii2bin[f[2] & 0x7f]) & 0x80) != 0)) break;
    uVar4 = uVar5 | (uint)(byte)data_ascii2bin[f[2] & 0x7f] << 6;
    t[iVar2] = (uchar)(uVar5 >> 0x10);
    iVar2 = iVar2 + 3;
    puVar3[2] = (uchar)uVar4;
    puVar3[1] = (uchar)(uVar4 >> 8);
    puVar3 = puVar3 + 3;
    if (t + ((n - 1U >> 2) + 1) * 3 == puVar3) {
      return iVar2;
    }
    f = f + 4;
    uVar5 = (uint)(byte)data_ascii2bin[*f & 0x7f];
  }
  return -1;
}

