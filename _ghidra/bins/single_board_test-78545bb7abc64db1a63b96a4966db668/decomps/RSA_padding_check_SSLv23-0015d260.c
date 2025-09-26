
int RSA_padding_check_SSLv23(uchar *to,int tlen,uchar *f,int fl,int rsa_len)

{
  byte *pbVar1;
  byte bVar2;
  byte bVar3;
  void *pvVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  uint uVar9;
  byte *pbVar10;
  byte *pbVar11;
  uint uVar12;
  uint uVar13;
  uint uVar14;
  uint uVar15;
  byte *pbVar16;
  uint uVar17;
  byte *pbVar18;
  uint uVar19;
  bool bVar20;
  bool bVar21;
  
  bVar20 = fl < 0;
  bVar21 = fl == 0;
  if (0 < fl) {
    bVar20 = tlen < 0;
    bVar21 = tlen == 0;
  }
  if (bVar21 || bVar20) {
    uVar5 = 0xffffffff;
  }
  else if (rsa_len < fl || rsa_len < 0xb) {
    ERR_put_error(4,0x72,0x6f,"crypto/rsa/rsa_ssl.c",0x4a);
    uVar5 = 0xffffffff;
  }
  else {
    pvVar4 = CRYPTO_malloc(rsa_len,"crypto/rsa/rsa_ssl.c",0x4e);
    pbVar18 = f + fl;
    iVar8 = 0;
    pbVar1 = (byte *)((int)pvVar4 + rsa_len);
    if (pvVar4 == (void *)0x0) {
      ERR_put_error(4,0x72,0x41,"crypto/rsa/rsa_ssl.c",0x50);
      uVar5 = 0xffffffff;
    }
    else {
      do {
        pbVar16 = pbVar1;
        iVar8 = iVar8 + 1;
        uVar6 = ~((int)(fl - 1U & ~fl) >> 0x1f);
        uVar5 = uVar6 & 1;
        pbVar18 = pbVar18 + -uVar5;
        fl = fl - uVar5;
        uVar6 = uVar6 & *pbVar18;
        pbVar1 = pbVar16 + -1;
        *pbVar1 = (byte)uVar6;
      } while (iVar8 < rsa_len);
      uVar5 = 0;
      uVar9 = 0;
      uVar12 = 0;
      uVar19 = 2;
      uVar6 = (int)(uVar6 - 1 & ~uVar6 & (*pbVar16 ^ 2) - 1 & ~(*pbVar16 ^ 2)) >> 0x1f;
      uVar17 = ~uVar6;
      pbVar18 = pbVar16;
      do {
        pbVar18 = pbVar18 + 1;
        uVar13 = (uint)*pbVar18;
        uVar7 = (int)(uVar13 - 1 & ~uVar13) >> 0x1f;
        uVar14 = uVar7 & ~uVar12;
        uVar12 = uVar12 | uVar7;
        uVar7 = uVar19 & uVar14;
        uVar19 = uVar19 + 1;
        uVar9 = uVar9 + (uVar12 & 1 ^ 1) &
                (uVar12 | (int)((uVar13 ^ 3) - 1 & ~(uVar13 ^ 3)) >> 0x1f);
        uVar5 = uVar7 | uVar5 & ~uVar14;
      } while ((int)uVar19 < rsa_len);
      uVar7 = rsa_len - (uVar5 + 1);
      uVar6 = uVar6 & ~((int)((uVar5 ^ 10 | uVar5 - 10 ^ 10) ^ uVar5) >> 0x1f);
      uVar19 = uVar6 & (int)(uVar9 ^ (uVar9 ^ 8 | uVar9 - 8 ^ 8)) >> 0x1f;
      uVar5 = uVar17 | uVar6;
      uVar13 = rsa_len - 0xb;
      uVar9 = uVar19 & ~((int)((tlen ^ uVar7 | tlen - uVar7 ^ uVar7) ^ tlen) >> 0x1f);
      uVar12 = (int)((tlen ^ uVar13 | uVar13 - tlen ^ tlen) ^ uVar13) >> 0x1f;
      uVar12 = uVar13 & uVar12 | tlen & ~uVar12;
      if (1 < (int)uVar13) {
        uVar14 = 1;
        do {
          uVar15 = uVar14 & uVar13 - uVar7;
          bVar2 = (char)((byte)(uVar15 - 1 >> 0x18) & ~(byte)(uVar15 >> 0x18)) >> 7;
          if (0xb < (int)(rsa_len - uVar14)) {
            pbVar18 = pbVar1 + uVar14 + 10;
            pbVar10 = pbVar16 + 10;
            do {
              pbVar18 = pbVar18 + 1;
              pbVar11 = pbVar10 + 1;
              *pbVar10 = bVar2 & *pbVar10 | ~bVar2 & *pbVar18;
              pbVar10 = pbVar11;
            } while (pbVar1 + (rsa_len - uVar14) != pbVar11);
          }
          uVar15 = uVar14 * 2;
          iVar8 = uVar14 * -2;
          uVar14 = uVar15;
        } while (uVar13 != uVar15 && (int)(uVar13 + iVar8) < 0 == SBORROW4(uVar13,uVar15));
      }
      if (uVar12 != 0) {
        pbVar16 = pbVar16 + 9;
        uVar13 = 0;
        do {
          iVar8 = uVar13 - uVar7;
          bVar2 = (byte)(uVar7 >> 0x18);
          bVar3 = (byte)(uVar13 >> 0x18);
          pbVar16 = pbVar16 + 1;
          uVar13 = uVar13 + 1;
          bVar2 = (byte)uVar9 &
                  (char)(((byte)((uint)iVar8 >> 0x18) ^ bVar2 | bVar2 ^ bVar3) ^ bVar3) >> 7;
          *to = *to & ~bVar2 | *pbVar16 & bVar2;
          to = to + 1;
        } while (uVar13 != uVar12);
      }
      CRYPTO_clear_free(pbVar1,rsa_len,"crypto/rsa/rsa_ssl.c",0xab);
      ERR_put_error(4,0x72,(uVar9 | ~uVar19) &
                           ((~uVar5 & 0x71 | uVar17 & uVar5 & 0x6b) & (uVar19 | ~uVar6) |
                           ~(uVar19 | ~uVar6) & 0x73) | ~(uVar9 | ~uVar19) & 0x6d,
                    "crypto/rsa/rsa_ssl.c",0xac);
      err_clear_last_constant_time(uVar9 & 1);
      uVar5 = uVar7 & uVar9 | ~uVar9;
    }
  }
  return uVar5;
}

