
int i2c_ASN1_INTEGER(ASN1_INTEGER *a,uchar **pp)

{
  byte bVar1;
  uchar *puVar2;
  uint uVar3;
  byte *pbVar4;
  int iVar5;
  byte *pbVar6;
  uint uVar7;
  byte *pbVar8;
  uint uVar9;
  int iVar10;
  uint uVar11;
  
  pbVar4 = a->data;
  uVar7 = a->length;
  if (pbVar4 == (byte *)0x0 || uVar7 == 0) {
    uVar7 = 0;
    uVar11 = 1;
    uVar3 = uVar7;
    uVar9 = uVar7;
  }
  else {
    bVar1 = *pbVar4;
    uVar9 = a->type & 0x100;
    if (bVar1 < 0x80 || uVar9 != 0) {
      uVar11 = uVar9;
      if (uVar9 != 0) {
        if (bVar1 < 0x81) {
          uVar11 = 0;
          if (bVar1 == 0x80) {
            if (uVar7 == 1) {
              uVar9 = 0;
            }
            else {
              if (uVar7 < 0x22) {
                iVar5 = 1;
                bVar1 = 0;
              }
              else {
                bVar1 = 0;
                pbVar8 = pbVar4 + 0x23;
                iVar10 = 1;
                do {
                  iVar5 = iVar10 + 0x20;
                  uVar9 = iVar10 + 0x21;
                  HintPreloadData(pbVar8);
                  bVar1 = bVar1 | pbVar8[-0xf] |
                                  pbVar8[-0x10] |
                                  pbVar8[-0x11] |
                                  pbVar8[-0x12] |
                                  pbVar8[-0x13] |
                                  pbVar8[-0x14] |
                                  pbVar8[-0x15] |
                                  pbVar8[-0x16] |
                                  pbVar8[-0x17] |
                                  pbVar8[-0x18] |
                                  pbVar8[-0x19] |
                                  pbVar8[-0x1a] |
                                  pbVar8[-0x1b] |
                                  pbVar8[-0x1c] |
                                  pbVar8[-0x1d] |
                                  pbVar8[-0x22] | pbVar8[-0x21] | pbVar8[-0x20] | pbVar8[-0x1f] |
                                  pbVar8[-0x1e] | pbVar8[-0xe] | pbVar8[-0xd] | pbVar8[-0xc] |
                                  pbVar8[-0xb] | pbVar8[-10] | pbVar8[-9] | pbVar8[-8] | pbVar8[-7]
                                  | pbVar8[-6] | pbVar8[-5] | pbVar8[-4] | pbVar8[-3];
                  pbVar8 = pbVar8 + 0x20;
                  iVar10 = iVar5;
                } while (uVar9 < uVar7 - 0x1f);
              }
              pbVar8 = pbVar4 + iVar5;
              do {
                pbVar6 = pbVar8 + 1;
                bVar1 = bVar1 | *pbVar8;
                pbVar8 = pbVar6;
              } while ((uint)((int)pbVar6 - (int)pbVar4) < uVar7);
              if (bVar1 == 0) {
                uVar9 = 0;
              }
              else {
                uVar9 = 0xff;
              }
              uVar11 = uVar9 & 1;
            }
          }
          else {
            uVar9 = 0xff;
          }
        }
        else {
          uVar9 = 0xff;
          uVar11 = 1;
        }
      }
    }
    else {
      uVar9 = 0;
      uVar11 = 1;
    }
    uVar11 = uVar11 + uVar7;
    uVar3 = uVar11;
  }
  if ((pp != (uchar **)0x0) && (puVar2 = *pp, puVar2 != (uchar *)0x0)) {
    *puVar2 = (uchar)uVar9;
    puVar2 = puVar2 + uVar3;
    pbVar4 = pbVar4 + uVar7;
    uVar3 = uVar9 & 1;
    if (uVar7 != 0) {
      pbVar8 = pbVar4 + -uVar7;
      do {
        pbVar4 = pbVar4 + -1;
        uVar3 = uVar3 + (*pbVar4 ^ uVar9);
        puVar2 = puVar2 + -1;
        *puVar2 = (uchar)uVar3;
        uVar3 = uVar3 >> 8;
      } while (pbVar4 != pbVar8);
    }
    *pp = *pp + uVar11;
    return uVar11;
  }
  return uVar11;
}

