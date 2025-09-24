
void WHIRLPOOL_BitUpdate(WHIRLPOOL_CTX *c,void *inp,size_t bits)

{
  uint uVar1;
  size_t sVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  uchar *puVar6;
  uint uVar7;
  uint uVar8;
  void *__src;
  byte bVar9;
  uint uVar10;
  
  uVar7 = c->bitoff;
  uVar1 = c->bitlen[0] + bits;
  uVar10 = -bits & 7;
  c->bitlen[0] = uVar1;
  uVar8 = uVar7 & 7;
  if (((((uVar1 < bits) && (sVar2 = c->bitlen[1] + 1, c->bitlen[1] = sVar2, sVar2 == 0)) &&
       (sVar2 = c->bitlen[2] + 1, c->bitlen[2] = sVar2, sVar2 == 0)) &&
      ((sVar2 = c->bitlen[3] + 1, c->bitlen[3] = sVar2, sVar2 == 0 &&
       (sVar2 = c->bitlen[4] + 1, c->bitlen[4] = sVar2, sVar2 == 0)))) &&
     ((sVar2 = c->bitlen[5] + 1, c->bitlen[5] = sVar2, sVar2 == 0 &&
      (sVar2 = c->bitlen[6] + 1, c->bitlen[6] = sVar2, sVar2 == 0)))) {
    c->bitlen[7] = c->bitlen[7] + 1;
  }
  __src = inp;
  if (((uVar7 | -bits) & 7) == 0) {
LAB_001c61e2:
    if (bits != 0) {
      puVar6 = c->data;
      do {
        while( true ) {
          uVar10 = uVar7 >> 3;
          uVar8 = 0x200 - uVar7;
          uVar1 = bits >> 3;
          if ((uVar7 == 0) && (uVar5 = bits >> 9, uVar5 != 0)) break;
          uVar7 = uVar7 + bits;
          if (bits < uVar8) {
            bits = 0;
            memcpy(puVar6 + uVar10,__src,uVar1);
          }
          else {
            uVar7 = 0;
            bits = bits - uVar8;
            memcpy(puVar6 + uVar10,__src,uVar8 >> 3);
            whirlpool_block(c,puVar6,1);
            __src = (void *)((int)__src + (uVar8 >> 3));
          }
          c->bitoff = uVar7;
          if (bits == 0) {
            return;
          }
        }
        bits = bits & 0x1ff;
        whirlpool_block(c,__src,uVar5);
        __src = (void *)((int)__src + uVar5 * 0x40);
      } while (bits != 0);
    }
    return;
  }
  if (bits == 0) {
    return;
  }
  uVar1 = uVar7 >> 3;
  if (uVar8 == uVar10) {
                    /* WARNING: Load size is inaccurate */
    __src = (void *)((int)inp + 1);
    uVar7 = uVar7 + (8 - uVar8);
    bits = bits - (8 - uVar8);
    c->data[uVar1] = (byte)(0xff >> uVar8) & *inp | c->data[uVar1];
    if (uVar7 == 0x200) {
      uVar7 = 0;
      whirlpool_block(c,c->data,1);
    }
    c->bitoff = uVar7;
    goto LAB_001c61e2;
  }
  if (uVar8 == 0) {
    while (8 < bits) {
      uVar7 = uVar7 + 8;
                    /* WARNING: Load size is inaccurate */
      bits = bits - 8;
      c->data[uVar1] =
           *inp << uVar10 | (byte)((int)(uint)*(byte *)((int)inp + 1) >> (8 - uVar10 & 0xff));
      if (0x1ff < uVar7) {
        uVar7 = uVar7 & 0x1ff;
        whirlpool_block(c,c->data,1);
      }
      c->bitoff = uVar7;
      uVar1 = uVar7 >> 3;
      inp = (char *)((int)inp + 1);
    }
                    /* WARNING: Load size is inaccurate */
    uVar5 = bits + uVar7;
    bVar9 = *inp << uVar10;
    c->data[uVar1] = bVar9;
    if (uVar5 != 0x200) goto LAB_001c6176;
LAB_001c6196:
    whirlpool_block(c,c->data,1);
    uVar5 = uVar8;
    if (uVar8 == 0) goto LAB_001c6176;
    uVar4 = 0;
    uVar10 = (uint)bVar9;
    uVar5 = uVar4;
  }
  else {
    while (8 < bits) {
      uVar7 = uVar7 + 8;
                    /* WARNING: Load size is inaccurate */
      bits = bits - 8;
      iVar3 = uVar1 + 1;
      uVar5 = ((int)(uint)*(byte *)((int)inp + 1) >> (8 - uVar10 & 0xff) | (uint)*inp << uVar10) &
              0xff;
      c->data[uVar1] = c->data[uVar1] | (byte)((int)uVar5 >> uVar8);
      if (0x1ff < uVar7) {
        whirlpool_block(c,c->data);
        uVar7 = uVar7 & 0x1ff;
        iVar3 = 0;
      }
      uVar1 = uVar7 >> 3;
      c->data[iVar3] = (uchar)(uVar5 << (8 - uVar8 & 0xff));
      c->bitoff = uVar7;
      inp = (byte *)((int)inp + 1);
    }
                    /* WARNING: Load size is inaccurate */
    uVar4 = uVar1 + 1;
    bVar9 = (byte)((uint)*inp << uVar10);
    uVar10 = (uint)*inp << uVar10 & 0xff;
    c->data[uVar1] = c->data[uVar1] | (byte)((int)uVar10 >> uVar8);
    uVar5 = bits + uVar7;
    if (bits + uVar7 == 0x200) goto LAB_001c6196;
  }
  c->data[uVar4] = (uchar)(uVar10 << (8 - uVar8 & 0xff));
LAB_001c6176:
  c->bitoff = uVar5;
  return;
}

