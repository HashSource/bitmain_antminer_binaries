
int RSA_padding_check_PKCS1_type_2(uchar *to,int tlen,uchar *f,int fl,int rsa_len)

{
  byte *pbVar1;
  byte bVar2;
  byte bVar3;
  void *pvVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  int iVar9;
  uint uVar10;
  byte *pbVar11;
  byte *pbVar12;
  byte *pbVar13;
  byte *pbVar14;
  uint uVar15;
  bool bVar16;
  bool bVar17;
  
  bVar16 = fl < 0;
  bVar17 = fl == 0;
  if (0 < fl) {
    bVar16 = tlen < 0;
    bVar17 = tlen == 0;
  }
  if (bVar17 || bVar16) {
    uVar5 = 0xffffffff;
  }
  else if (rsa_len < fl || rsa_len < 0xb) {
    ERR_put_error(4,0x71,0x9f,"crypto/rsa/rsa_pk1.c",0xae);
    uVar5 = 0xffffffff;
  }
  else {
    pvVar4 = CRYPTO_malloc(rsa_len,"crypto/rsa/rsa_pk1.c",0xb2);
    pbVar14 = f + fl;
    iVar9 = 0;
    pbVar1 = (byte *)((int)pvVar4 + rsa_len);
    if (pvVar4 == (void *)0x0) {
      ERR_put_error(4,0x71,0x41,"crypto/rsa/rsa_pk1.c",0xb4);
      uVar5 = 0xffffffff;
    }
    else {
      do {
        pbVar13 = pbVar1;
        iVar9 = iVar9 + 1;
        uVar7 = ~((int)(fl - 1U & ~fl) >> 0x1f);
        uVar5 = uVar7 & 1;
        pbVar14 = pbVar14 + -uVar5;
        fl = fl - uVar5;
        uVar7 = uVar7 & *pbVar14;
        pbVar1 = pbVar13 + -1;
        *pbVar1 = (byte)uVar7;
      } while (iVar9 < rsa_len);
      uVar6 = 0;
      uVar15 = 0;
      uVar5 = 2;
      pbVar14 = pbVar13;
      do {
        pbVar14 = pbVar14 + 1;
        uVar10 = (int)(*pbVar14 - 1 & ~(uint)*pbVar14) >> 0x1f;
        uVar8 = uVar10 & ~uVar15;
        uVar15 = uVar15 | uVar10;
        uVar10 = uVar5 & uVar8;
        uVar5 = uVar5 + 1;
        uVar6 = uVar10 | ~uVar8 & uVar6;
      } while ((int)uVar5 < rsa_len);
      uVar8 = rsa_len - 0xb;
      uVar15 = rsa_len - (uVar6 + 1);
      uVar5 = (int)((tlen ^ uVar8 | uVar8 - tlen ^ tlen) ^ uVar8) >> 0x1f;
      uVar5 = uVar8 & uVar5 | ~uVar5 & tlen;
      uVar7 = (int)(uVar7 - 1 & ~uVar7 & (*pbVar13 ^ 2) - 1 & ~(*pbVar13 ^ 2)) >> 0x1f &
              ~((int)((uVar6 - 10 ^ 10 | uVar6 ^ 10) ^ uVar6) >> 0x1f) &
              ~((int)((tlen - uVar15 ^ uVar15 | tlen ^ uVar15) ^ tlen) >> 0x1f);
      if (1 < (int)uVar8) {
        uVar6 = 1;
        do {
          uVar10 = uVar6 & uVar8 - uVar15;
          bVar2 = (char)((byte)(uVar10 - 1 >> 0x18) & ~(byte)(uVar10 >> 0x18)) >> 7;
          if (0xb < (int)(rsa_len - uVar6)) {
            pbVar14 = pbVar1 + uVar6 + 10;
            pbVar11 = pbVar13 + 10;
            do {
              pbVar14 = pbVar14 + 1;
              pbVar12 = pbVar11 + 1;
              *pbVar11 = bVar2 & *pbVar11 | ~bVar2 & *pbVar14;
              pbVar11 = pbVar12;
            } while (pbVar1 + (rsa_len - uVar6) != pbVar12);
          }
          uVar10 = uVar6 * 2;
          iVar9 = uVar6 * -2;
          uVar6 = uVar10;
        } while (uVar8 != uVar10 && (int)(uVar8 + iVar9) < 0 == SBORROW4(uVar8,uVar10));
      }
      if (uVar5 != 0) {
        pbVar13 = pbVar13 + 9;
        uVar6 = 0;
        do {
          iVar9 = uVar6 - uVar15;
          bVar2 = (byte)(uVar15 >> 0x18);
          bVar3 = (byte)(uVar6 >> 0x18);
          pbVar13 = pbVar13 + 1;
          uVar6 = uVar6 + 1;
          bVar2 = (byte)uVar7 &
                  (char)(((byte)((uint)iVar9 >> 0x18) ^ bVar2 | bVar2 ^ bVar3) ^ bVar3) >> 7;
          *to = *to & ~bVar2 | *pbVar13 & bVar2;
          to = to + 1;
        } while (uVar6 != uVar5);
      }
      CRYPTO_clear_free(pbVar1,rsa_len,"crypto/rsa/rsa_pk1.c",0xfa);
      ERR_put_error(4,0x71,0x9f,"crypto/rsa/rsa_pk1.c",0xfb);
      err_clear_last_constant_time(uVar7 & 1);
      uVar5 = uVar15 & uVar7 | ~uVar7;
    }
  }
  return uVar5;
}

