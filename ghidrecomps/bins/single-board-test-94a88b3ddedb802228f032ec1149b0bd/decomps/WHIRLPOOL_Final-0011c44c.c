
int WHIRLPOOL_Final(uchar *md,WHIRLPOOL_CTX *c)

{
  byte bVar1;
  uchar *puVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  uint uVar5;
  size_t sVar6;
  undefined4 uVar7;
  uint uVar8;
  WHIRLPOOL_CTX *pWVar9;
  WHIRLPOOL_CTX *pWVar10;
  size_t sVar11;
  size_t sVar12;
  size_t sVar13;
  size_t sVar14;
  size_t sVar15;
  bool bVar16;
  
  uVar5 = c->bitoff >> 3;
  uVar8 = c->bitoff & 7;
  bVar16 = uVar8 == 0;
  puVar2 = md;
  pWVar9 = c;
  if (!bVar16) {
    pWVar9 = (WHIRLPOOL_CTX *)(c->data + (uVar5 - 0x40));
    uVar8 = 0x80 >> uVar8;
    puVar2 = (uchar *)(uint)pWVar9->data[0];
  }
  if (bVar16) {
    bVar1 = 0x80;
    pWVar9 = (WHIRLPOOL_CTX *)(c->data + (uVar5 - 0x40));
  }
  else {
    bVar1 = (byte)puVar2 | (byte)uVar8;
  }
  uVar8 = uVar5 + 1;
  pWVar9->data[0] = bVar1;
  if (uVar8 < 0x21) {
    if (uVar8 == 0x20) goto LAB_0011c4ac;
    sVar6 = 0x1f - uVar5;
  }
  else {
    if (uVar8 < 0x40) {
      memset(c->data + uVar5 + 1,0,0x3f - uVar5);
    }
    whirlpool_block(c,c->data,1);
    sVar6 = 0x20;
    uVar8 = 0;
  }
  memset(c->data + uVar8,0,sVar6);
LAB_0011c4ac:
  sVar14 = c->bitlen[0];
  sVar13 = c->bitlen[1];
  sVar12 = c->bitlen[2];
  sVar6 = c->bitlen[4];
  c->data[0x3f] = (uchar)sVar14;
  sVar11 = c->bitlen[3];
  c->data[0x3e] = (uchar)(sVar14 >> 8);
  c->data[0x3d] = (uchar)(sVar14 >> 0x10);
  c->data[0x3c] = (uchar)(sVar14 >> 0x18);
  c->data[0x3b] = (uchar)sVar13;
  c->data[0x3a] = (uchar)(sVar13 >> 8);
  c->data[0x36] = (uchar)(sVar12 >> 8);
  c->data[0x35] = (uchar)(sVar12 >> 0x10);
  c->data[0x34] = (uchar)(sVar12 >> 0x18);
  sVar14 = c->bitlen[5];
  c->data[0x39] = (uchar)(sVar13 >> 0x10);
  c->data[0x38] = (uchar)(sVar13 >> 0x18);
  sVar13 = c->bitlen[6];
  c->data[0x37] = (uchar)sVar12;
  c->data[0x33] = (uchar)sVar11;
  c->data[0x32] = (uchar)(sVar11 >> 8);
  c->data[0x31] = (uchar)(sVar11 >> 0x10);
  sVar12 = c->bitlen[4];
  c->data[0x2c] = (uchar)(sVar6 >> 0x18);
  sVar15 = c->bitlen[5];
  c->data[0x2f] = (uchar)sVar12;
  c->data[0x30] = (uchar)(sVar11 >> 0x18);
  c->data[0x2e] = (uchar)(sVar6 >> 8);
  c->data[0x2d] = (uchar)(sVar6 >> 0x10);
  c->data[0x2b] = (uchar)sVar15;
  c->data[0x2a] = (uchar)(sVar14 >> 8);
  c->data[0x29] = (uchar)(sVar14 >> 0x10);
  c->data[0x28] = (uchar)(sVar14 >> 0x18);
  c->data[0x27] = (uchar)sVar13;
  c->data[0x25] = (uchar)(sVar13 >> 0x10);
  sVar6 = c->bitlen[7];
  c->data[0x26] = (uchar)(sVar13 >> 8);
  c->data[0x24] = (uchar)(sVar13 >> 0x18);
  c->data[0x23] = (uchar)sVar6;
  c->data[0x22] = (uchar)(sVar6 >> 8);
  c->data[0x20] = (uchar)(sVar6 >> 0x18);
  c->data[0x21] = (uchar)(sVar6 >> 0x10);
  whirlpool_block(c,c->data,1);
  pWVar9 = c;
  if (md != (uchar *)0x0) {
    do {
      uVar3 = *(undefined4 *)((int)&pWVar9->H + 4);
      uVar4 = *(undefined4 *)((int)&pWVar9->H + 8);
      uVar7 = *(undefined4 *)((int)&pWVar9->H + 0xc);
      pWVar10 = (WHIRLPOOL_CTX *)((int)&pWVar9->H + 0x10);
      *(undefined4 *)md = *(undefined4 *)&pWVar9->H;
      *(undefined4 *)((int)md + 4) = uVar3;
      *(undefined4 *)((int)md + 8) = uVar4;
      *(undefined4 *)((int)md + 0xc) = uVar7;
      md = (uchar *)((int)md + 0x10);
      pWVar9 = pWVar10;
    } while (pWVar10 != (WHIRLPOOL_CTX *)c->data);
    memset(c,0,0xa8);
    md = (uchar *)0x1;
  }
  return (int)md;
}

