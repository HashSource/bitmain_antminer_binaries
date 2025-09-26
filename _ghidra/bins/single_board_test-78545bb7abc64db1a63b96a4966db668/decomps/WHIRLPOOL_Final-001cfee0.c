
int WHIRLPOOL_Final(uchar *md,WHIRLPOOL_CTX *c)

{
  uchar *puVar1;
  undefined4 uVar2;
  uint uVar3;
  undefined4 uVar4;
  uint uVar5;
  size_t sVar6;
  undefined4 uVar7;
  byte bVar8;
  uint uVar9;
  size_t sVar10;
  size_t sVar11;
  WHIRLPOOL_CTX *pWVar12;
  WHIRLPOOL_CTX *pWVar13;
  byte unaff_r6;
  size_t sVar14;
  size_t sVar15;
  size_t sVar16;
  size_t sVar17;
  bool bVar18;
  
  uVar3 = c->bitoff >> 3;
  uVar9 = c->bitoff & 7;
  bVar18 = uVar9 != 0;
  puVar1 = md;
  if (bVar18) {
    puVar1 = c->data + (uVar3 - 0x40);
    uVar9 = 0x80 >> uVar9;
  }
  if (bVar18) {
    unaff_r6 = (byte)*(uint *)(puVar1 + 0x40);
  }
  uVar5 = uVar3 + 1;
  if (bVar18) {
    bVar8 = (byte)uVar9 | unaff_r6;
  }
  else {
    bVar8 = 0x80;
    puVar1 = c->data + (uVar3 - 0x40);
  }
  puVar1[0x40] = bVar8;
  if (uVar5 < 0x21) {
    if (uVar5 == 0x20) goto LAB_001cff36;
    sVar6 = 0x20 - uVar5;
    puVar1 = c->data + uVar3 + 1;
  }
  else {
    if (uVar5 < 0x40) {
      memset(c->data + uVar3 + 1,0,0x40 - uVar5);
    }
    puVar1 = c->data;
    whirlpool_block(c,puVar1,1);
    sVar6 = 0x20;
  }
  memset(puVar1,0,sVar6);
LAB_001cff36:
  sVar10 = c->bitlen[0];
  sVar15 = c->bitlen[1];
  sVar16 = c->bitlen[2];
  sVar17 = c->bitlen[3];
  c->data[0x3b] = (uchar)sVar15;
  c->data[0x37] = (uchar)sVar16;
  c->data[0x3e] = (uchar)(sVar10 >> 8);
  sVar14 = c->bitlen[4];
  c->data[0x3c] = (uchar)(sVar10 >> 0x18);
  sVar6 = c->bitlen[5];
  c->data[0x3a] = (uchar)(sVar15 >> 8);
  c->data[0x33] = (uchar)sVar17;
  c->data[0x3f] = (uchar)sVar10;
  c->data[0x38] = (uchar)(sVar15 >> 0x18);
  sVar11 = c->bitlen[6];
  c->data[0x36] = (uchar)(sVar16 >> 8);
  c->data[0x2f] = (uchar)sVar14;
  c->data[0x2b] = (uchar)sVar6;
  c->data[0x34] = (uchar)(sVar16 >> 0x18);
  c->data[0x27] = (uchar)sVar11;
  c->data[0x32] = (uchar)(sVar17 >> 8);
  c->data[0x3d] = (uchar)(sVar10 >> 0x10);
  c->data[0x31] = (uchar)(sVar17 >> 0x10);
  c->data[0x30] = (uchar)(sVar17 >> 0x18);
  c->data[0x39] = (uchar)(sVar15 >> 0x10);
  c->data[0x2d] = (uchar)(sVar14 >> 0x10);
  c->data[0x2c] = (uchar)(sVar14 >> 0x18);
  c->data[0x2a] = (uchar)(sVar6 >> 8);
  c->data[0x29] = (uchar)(sVar6 >> 0x10);
  c->data[0x28] = (uchar)(sVar6 >> 0x18);
  c->data[0x35] = (uchar)(sVar16 >> 0x10);
  c->data[0x2e] = (uchar)(sVar14 >> 8);
  c->data[0x26] = (uchar)(sVar11 >> 8);
  sVar6 = c->bitlen[7];
  c->data[0x24] = (uchar)(sVar11 >> 0x18);
  c->data[0x25] = (uchar)(sVar11 >> 0x10);
  c->data[0x23] = (uchar)sVar6;
  c->data[0x22] = (uchar)(sVar6 >> 8);
  c->data[0x21] = (uchar)(sVar6 >> 0x10);
  c->data[0x20] = (uchar)(sVar6 >> 0x18);
  whirlpool_block(c,c->data,1);
  pWVar12 = c;
  if (md != (uchar *)0x0) {
    do {
      pWVar13 = (WHIRLPOOL_CTX *)((int)&pWVar12->H + 0x10);
      uVar2 = *(undefined4 *)((int)&pWVar12->H + 4);
      uVar4 = *(undefined4 *)((int)&pWVar12->H + 8);
      uVar7 = *(undefined4 *)((int)&pWVar12->H + 0xc);
      *(undefined4 *)md = *(undefined4 *)&pWVar12->H;
      *(undefined4 *)(md + 4) = uVar2;
      *(undefined4 *)(md + 8) = uVar4;
      *(undefined4 *)(md + 0xc) = uVar7;
      pWVar12 = pWVar13;
      md = md + 0x10;
    } while (pWVar13 != (WHIRLPOOL_CTX *)c->data);
    OPENSSL_cleanse(c,0xa8);
    return 1;
  }
  return 0;
}

