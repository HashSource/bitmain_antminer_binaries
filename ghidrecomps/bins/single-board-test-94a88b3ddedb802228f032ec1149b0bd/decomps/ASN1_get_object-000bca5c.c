
int ASN1_get_object(uchar **pp,long *plength,int *ptag,int *pclass,long omax)

{
  byte bVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  byte *pbVar5;
  int iVar6;
  uint uVar7;
  byte *pbVar8;
  byte *pbVar9;
  byte *pbVar10;
  
  pbVar5 = *pp;
  if (omax != 0) {
    bVar1 = *pbVar5;
    uVar2 = (uint)bVar1;
    uVar7 = uVar2 & 0x1f;
    if (uVar7 == 0x1f) {
      iVar6 = omax + -1;
      if (iVar6 != 0) {
        uVar3 = 0;
        pbVar8 = pbVar5 + 1;
        while( true ) {
          pbVar10 = pbVar8 + 1;
          uVar7 = (uint)*pbVar8;
          if ((*pbVar8 & 0x80) == 0) break;
          iVar6 = iVar6 + -1;
          uVar3 = uVar7 & 0x7f | uVar3 << 7;
          if ((iVar6 == 0) || (pbVar8 = pbVar10, 0xffffff < (int)uVar3)) goto LAB_000bca7a;
        }
        iVar6 = iVar6 + -1;
        if (iVar6 != 0) {
          uVar7 = uVar7 & 0x7f;
        }
        if (iVar6 != 0) {
          uVar7 = uVar7 | uVar3 << 7;
          goto LAB_000bcac6;
        }
      }
    }
    else {
      iVar6 = omax + -1;
      if (iVar6 != 0) {
        pbVar10 = pbVar5 + 1;
LAB_000bcac6:
        *ptag = uVar7;
        *pclass = uVar2 & 0xc0;
        if (0 < iVar6) {
          uVar7 = (uint)*pbVar10;
          uVar2 = uVar2 & 0x20;
          if (uVar7 == 0x80) {
            uVar3 = 0;
            *plength = 0;
            if ((bVar1 & 0x20) != 0) {
              pbVar8 = pbVar10 + 1;
              uVar7 = 1;
LAB_000bcafc:
              if ((int)(pbVar5 + (omax - (int)pbVar8)) < (int)uVar3) {
                uVar2 = uVar2 | 0x80;
                ERR_put_error(0xd,0x72,0x9b,DAT_000bcb70,0x93);
              }
              *pp = pbVar8;
              return uVar2 | uVar7;
            }
          }
          else {
            uVar3 = uVar7 & 0x7f;
            pbVar8 = pbVar10 + 1;
            if ((int)(uVar7 << 0x18) < 0) {
              if ((uVar3 < 5) && (iVar6 != 1)) {
                iVar4 = uVar3 + 1;
                uVar3 = 0;
                do {
                  if (pbVar8 == pbVar10 + iVar4) goto LAB_000bcaf2;
                  pbVar9 = pbVar8 + 1;
                  uVar3 = (uint)*pbVar8 | uVar3 << 8;
                  pbVar8 = pbVar9;
                } while (pbVar9 != pbVar10 + iVar6);
              }
            }
            else {
LAB_000bcaf2:
              if (-1 < (int)uVar3) {
                *plength = uVar3;
                uVar7 = 0;
                goto LAB_000bcafc;
              }
            }
          }
        }
      }
    }
  }
LAB_000bca7a:
  ERR_put_error(0xd,0x72,0x7b,DAT_000bcb70,0x9d);
  return 0x80;
}

