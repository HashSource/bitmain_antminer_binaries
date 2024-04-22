
int ASN1_UTCTIME_print(BIO *fp,ASN1_UTCTIME *a)

{
  uint uVar1;
  undefined4 uVar2;
  byte *pbVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  
  iVar5 = a->length;
  pbVar3 = a->data;
  if (9 < iVar5) {
    if (((((*pbVar3 - 0x30 < 10) && (pbVar3[1] - 0x30 < 10)) && (pbVar3[2] - 0x30 < 10)) &&
        ((((pbVar3[3] - 0x30 < 10 && (pbVar3[4] - 0x30 < 10)) &&
          ((pbVar3[5] - 0x30 < 10 && ((pbVar3[6] - 0x30 < 10 && (pbVar3[7] - 0x30 < 10)))))) &&
         (pbVar3[8] - 0x30 < 10)))) && (pbVar3[9] - 0x30 < 10)) {
      iVar6 = (uint)pbVar3[1] + (uint)*pbVar3 * 10;
      iVar7 = iVar6 + -0x210;
      uVar8 = ((uint)pbVar3[3] + (uint)pbVar3[2] * 10) - 0x211;
      if (iVar7 < 0x32) {
        iVar7 = iVar6 + -0x1ac;
      }
      if (uVar8 < 0xc) {
        if ((((iVar5 < 0xc) || (uVar1 = (uint)pbVar3[10], uVar1 < 0x30)) || (0x39 < uVar1)) ||
           ((uVar4 = (uint)pbVar3[0xb], uVar4 < 0x30 || (0x39 < uVar4)))) {
          iVar6 = 0;
        }
        else {
          iVar6 = uVar4 + uVar1 * 10 + -0x210;
        }
        uVar2 = DAT_000b8764;
        if (pbVar3[iVar5 + -1] != 0x5a) {
          uVar2 = DAT_000b8760;
        }
        iVar5 = BIO_printf(fp,DAT_000b876c,*(undefined4 *)(DAT_000b8768 + uVar8 * 4),
                           (uint)pbVar3[5] + (uint)pbVar3[4] * 10 + -0x210,
                           (uint)pbVar3[7] + (uint)pbVar3[6] * 10 + -0x210,
                           (uint)pbVar3[9] + (uint)pbVar3[8] * 10 + -0x210,iVar6,iVar7 + 0x76c,uVar2
                          );
        return (uint)(0 < iVar5);
      }
    }
  }
  BIO_write(fp,DAT_000b875c,0xe);
  return 0;
}

