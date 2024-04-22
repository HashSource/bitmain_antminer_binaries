
void WHIRLPOOL_BitUpdate(WHIRLPOOL_CTX *c,void *inp,size_t bits)

{
  byte bVar1;
  int iVar2;
  uint uVar3;
  size_t sVar4;
  uchar *puVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  
  uVar6 = c->bitoff;
  uVar3 = bits + c->bitlen[0];
  uVar8 = -bits & 7;
  c->bitlen[0] = uVar3;
  uVar7 = uVar6 & 7;
  if (((((uVar3 < bits) && (sVar4 = c->bitlen[1] + 1, c->bitlen[1] = sVar4, sVar4 == 0)) &&
       (sVar4 = c->bitlen[2] + 1, c->bitlen[2] = sVar4, sVar4 == 0)) &&
      ((sVar4 = c->bitlen[3] + 1, c->bitlen[3] = sVar4, sVar4 == 0 &&
       (sVar4 = c->bitlen[4] + 1, c->bitlen[4] = sVar4, sVar4 == 0)))) &&
     ((sVar4 = c->bitlen[5] + 1, c->bitlen[5] = sVar4, sVar4 == 0 &&
      (sVar4 = c->bitlen[6] + 1, c->bitlen[6] = sVar4, sVar4 == 0)))) {
    c->bitlen[7] = c->bitlen[7] + 1;
  }
  if ((uVar8 | uVar7) != 0) {
    if (bits == 0) {
      return;
    }
    uVar3 = uVar6 >> 3;
    if (uVar7 != uVar8) {
      if (uVar7 == 0) {
        while (7 < bits) {
                    /* WARNING: Load size is inaccurate */
          bVar1 = *inp;
          uVar6 = uVar6 + 8;
                    /* WARNING: Load size is inaccurate */
          inp = (void *)((int)inp + 1);
          bits = bits - 8;
          c->data[uVar3] = (byte)((int)(uint)*inp >> (8 - uVar8 & 0xff)) | bVar1 << uVar8;
          if (0x1ff < uVar6) {
            uVar6 = uVar6 & 0x1ff;
            whirlpool_block(c,c->data,1);
          }
          c->bitoff = uVar6;
          if (bits == 0) {
            return;
          }
          uVar3 = uVar6 >> 3;
        }
                    /* WARNING: Load size is inaccurate */
        puVar5 = c->data + (uVar3 - 0x40);
        uVar9 = (uint)*inp << uVar8 & 0xff;
        uVar8 = uVar9;
      }
      else {
        if (7 < bits) {
          do {
            iVar2 = uVar3 + 1;
                    /* WARNING: Load size is inaccurate */
            bVar1 = *inp;
            uVar6 = uVar6 + 8;
                    /* WARNING: Load size is inaccurate */
            inp = (void *)((int)inp + 1);
            bits = bits - 8;
            uVar9 = ((int)(uint)*inp >> (8 - uVar8 & 0xff) | (uint)bVar1 << uVar8) & 0xff;
            c->data[uVar3] = (byte)((int)uVar9 >> uVar7) | c->data[uVar3];
            if (0x1ff < uVar6) {
              uVar6 = uVar6 & 0x1ff;
              whirlpool_block(c,c->data,1);
              iVar2 = 0;
            }
            c->bitoff = uVar6;
            uVar3 = uVar6 >> 3;
            c->data[iVar2] = (uchar)(uVar9 << (8 - uVar7 & 0xff));
            if (bits == 0) {
              return;
            }
          } while (7 < bits);
        }
                    /* WARNING: Load size is inaccurate */
        puVar5 = c->data + (uVar3 - 0x40);
        uVar8 = (uint)*inp << uVar8 & 0xff;
        uVar9 = (uint)puVar5[0x40] | (int)uVar8 >> uVar7 & 0xffU;
      }
      uVar3 = uVar3 + 1;
      puVar5[0x40] = (char)uVar9;
      uVar9 = bits + uVar6;
      if (bits + uVar6 == 0x200) {
        whirlpool_block(c,c->data,1);
        uVar3 = 0;
        uVar9 = uVar3;
      }
      if (uVar7 != 0) {
        c->data[uVar3] = (uchar)(uVar8 << (8 - uVar7 & 0xff));
      }
      c->bitoff = uVar9;
      return;
    }
                    /* WARNING: Load size is inaccurate */
    uVar6 = uVar6 + (8 - uVar7);
    bits = bits - (8 - uVar7);
    c->data[uVar3] = (byte)(0xff >> uVar7) & *inp | c->data[uVar3];
    if (uVar6 == 0x200) {
      uVar6 = 0;
      whirlpool_block(c,c->data,1);
    }
    c->bitoff = uVar6;
    inp = (void *)((int)inp + 1);
  }
  if (bits != 0) {
    do {
      while( true ) {
        uVar3 = 0x200 - uVar6;
        if ((uVar6 == 0) && (uVar7 = bits >> 9, uVar7 != 0)) break;
        uVar7 = uVar6 >> 3;
        uVar6 = uVar6 + bits;
        if (bits < uVar3) {
          uVar3 = bits >> 3;
          bits = 0;
          memcpy(c->data + uVar7,inp,uVar3);
        }
        else {
          bits = bits - uVar3;
          uVar6 = 0;
          memcpy(c->data + uVar7,inp,uVar3 >> 3);
          inp = (void *)((int)inp + (uVar3 >> 3));
          whirlpool_block(c,c->data,1);
        }
        c->bitoff = uVar6;
        if (bits == 0) {
          return;
        }
      }
      bits = bits & 0x1ff;
      whirlpool_block(c,inp,uVar7);
      inp = (void *)((int)inp + uVar7 * 0x40);
    } while (bits != 0);
  }
  return;
}

