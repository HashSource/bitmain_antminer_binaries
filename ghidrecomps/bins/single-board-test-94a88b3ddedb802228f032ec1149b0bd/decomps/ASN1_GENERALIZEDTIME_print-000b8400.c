
int ASN1_GENERALIZEDTIME_print(BIO *fp,ASN1_GENERALIZEDTIME *a)

{
  int iVar1;
  undefined4 uVar2;
  byte *pbVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  byte *pbVar9;
  uint uVar10;
  int iVar11;
  
  iVar4 = a->length;
  pbVar3 = a->data;
  if (0xb < iVar4) {
    if ((((((*pbVar3 - 0x30 < 10) && (pbVar3[1] - 0x30 < 10)) && (pbVar3[2] - 0x30 < 10)) &&
         (((pbVar3[3] - 0x30 < 10 && (pbVar3[4] - 0x30 < 10)) &&
          ((pbVar3[5] - 0x30 < 10 && ((pbVar3[6] - 0x30 < 10 && (pbVar3[7] - 0x30 < 10)))))))) &&
        (pbVar3[8] - 0x30 < 10)) &&
       (((((pbVar3[9] - 0x30 & 0xff) < 10 && (pbVar3[10] - 0x30 < 10)) &&
         ((pbVar3[0xb] - 0x30 & 0xff) < 10)) &&
        (uVar7 = ((uint)pbVar3[5] + (uint)pbVar3[4] * 10) - 0x211, uVar7 < 0xc)))) {
      if (((iVar4 < 0xe) || (uVar8 = (uint)pbVar3[0xc], uVar8 < 0x30)) ||
         ((0x39 < uVar8 || ((uVar10 = (uint)pbVar3[0xd], uVar10 < 0x30 || (0x39 < uVar10)))))) {
        iVar5 = 0;
        pbVar9 = (byte *)0x0;
        iVar11 = 0;
      }
      else {
        iVar11 = uVar10 + uVar8 * 10 + -0x210;
        if ((iVar4 == 0xe) || (pbVar3[0xe] != 0x2e)) {
          iVar5 = 0;
          pbVar9 = (byte *)0x0;
        }
        else {
          pbVar9 = pbVar3 + 0xe;
          if (((iVar4 == 0xf) || (pbVar3[0xf] < 0x30)) || (0x39 < pbVar3[0xf])) {
            iVar5 = 1;
          }
          else {
            iVar6 = 1;
            do {
              iVar5 = iVar6 + 1;
              if ((iVar5 == iVar4 + -0xe) || (iVar1 = iVar6 + 0xf, pbVar3[iVar1] < 0x30)) break;
              iVar6 = iVar5;
            } while (pbVar3[iVar1] < 0x3a);
          }
        }
      }
      uVar2 = DAT_000b8608;
      if (pbVar3[iVar4 + -1] == 0x5a) {
        uVar2 = DAT_000b860c;
      }
      iVar4 = BIO_printf(fp,DAT_000b8604,*(undefined4 *)(DAT_000b8600 + uVar7 * 4),
                         (uint)pbVar3[7] + (uint)pbVar3[6] * 10 + -0x210,
                         (pbVar3[9] - 0x30) + (uint)pbVar3[8] * 10 + -0x1e0,
                         (pbVar3[0xb] - 0x30) + (uint)pbVar3[10] * 10 + -0x1e0,iVar11,iVar5,pbVar9,
                         (uint)*pbVar3 * 1000 + (uint)pbVar3[1] * 100 + (uint)pbVar3[2] * 10 +
                         (pbVar3[3] - 0xd050),uVar2);
      return (uint)(0 < iVar4);
    }
  }
  BIO_write(fp,DAT_000b85fc,0xe);
  return 0;
}

