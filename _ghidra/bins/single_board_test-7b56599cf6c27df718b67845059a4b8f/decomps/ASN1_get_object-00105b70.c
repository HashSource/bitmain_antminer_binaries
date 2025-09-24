
int ASN1_get_object(uchar **pp,long *plength,int *ptag,int *pclass,long omax)

{
  byte bVar1;
  byte bVar2;
  ushort uVar3;
  uint3 uVar4;
  byte *pbVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  byte *pbVar9;
  byte *unaff_r10;
  byte *pbVar10;
  uint uVar11;
  
  if (omax != 0) {
    pbVar10 = *pp;
    bVar1 = *pbVar10;
    uVar11 = (uint)bVar1;
    uVar6 = uVar11 & 0x1f;
    if (uVar6 == 0x1f) {
      iVar8 = omax + -1;
      if (iVar8 != 0) {
        uVar6 = 0;
        pbVar9 = pbVar10 + 1;
        do {
          bVar2 = *pbVar9;
          if ((bVar2 & 0x80) == 0) {
            iVar8 = iVar8 + -1;
            if (iVar8 != 0) {
              unaff_r10 = pbVar9 + 1;
            }
            if (iVar8 != 0) {
              uVar6 = (uint)bVar2 | uVar6 << 7;
              goto LAB_00105bf4;
            }
            break;
          }
          iVar8 = iVar8 + -1;
          uVar6 = bVar2 & 0x7f | uVar6 << 7;
          pbVar9 = pbVar9 + 1;
        } while ((int)uVar6 < 0x1000000 && iVar8 != 0);
      }
    }
    else {
      iVar8 = omax + -1;
      if (iVar8 != 0) {
        unaff_r10 = pbVar10 + 1;
LAB_00105bf4:
        *ptag = uVar6;
        *pclass = uVar11 & 0xc0;
        if (0 < iVar8) {
          uVar6 = (uint)*unaff_r10;
          uVar11 = uVar11 & 0x20;
          if (uVar6 == 0x80) {
            uVar7 = 0;
            pbVar9 = unaff_r10 + 1;
            *plength = 0;
            uVar6 = 1;
            if ((bVar1 & 0x20) == 0) goto LAB_00105b90;
          }
          else {
            uVar7 = uVar6 & 0x7f;
            pbVar9 = unaff_r10 + 1;
            if ((int)(uVar6 << 0x18) < 0) {
              if (iVar8 + -1 <= (int)uVar7) goto LAB_00105b90;
              if ((*unaff_r10 & 0x7f) == 0) {
LAB_00105c84:
                uVar7 = 0;
              }
              else {
                uVar6 = uVar7;
                if (unaff_r10[1] == 0) {
                  pbVar5 = unaff_r10 + 2;
                  do {
                    pbVar9 = pbVar5;
                    uVar6 = uVar6 - 1;
                    if (uVar6 == 0) goto LAB_00105c84;
                    pbVar5 = pbVar9 + 1;
                  } while (*pbVar9 == 0);
                }
                if (4 < (int)uVar6) goto LAB_00105b90;
                uVar7 = (uint)*pbVar9;
                if (uVar6 != 1) {
                  uVar3 = CONCAT11(*pbVar9,pbVar9[1]);
                  uVar7 = (uint)uVar3;
                  if (uVar6 != 2) {
                    uVar4 = CONCAT21(uVar3,pbVar9[2]);
                    uVar7 = (uint)uVar4;
                    if (uVar6 != 3) {
                      uVar7 = CONCAT31(uVar4,pbVar9[3]);
                    }
                  }
                }
                pbVar9 = pbVar9 + uVar6;
                if ((int)uVar7 < 0) goto LAB_00105b90;
              }
            }
            uVar6 = 0;
            *plength = uVar7;
          }
          if (omax - ((int)pbVar9 - (int)pbVar10) < (int)uVar7) {
            ERR_put_error(0xd,0x72,0x9b,"crypto/asn1/asn1_lib.c",0x5b);
            uVar11 = uVar11 | 0x80;
          }
          *pp = pbVar9;
          return uVar11 | uVar6;
        }
      }
    }
  }
LAB_00105b90:
  ERR_put_error(0xd,0x72,0x7b,"crypto/asn1/asn1_lib.c",0x65);
  return 0x80;
}

