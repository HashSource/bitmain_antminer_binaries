
undefined4 c2i_uint64_int(uint *param_1,undefined4 param_2,undefined4 *param_3,uint param_4)

{
  byte bVar1;
  uint3 uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  byte *pbVar7;
  uint uVar8;
  byte *pbVar9;
  byte *pbVar10;
  int iVar11;
  int iVar12;
  byte local_28;
  undefined1 local_27;
  undefined1 local_26;
  undefined1 local_25;
  byte local_24;
  byte local_23;
  byte local_22;
  byte local_21;
  
  if (param_4 == 0) {
    ERR_put_error(0xd,0xe2,0xde,"crypto/asn1/a_int.c",0x9a);
    return 0;
  }
  pbVar7 = (byte *)*param_3;
  if (param_4 == 1) {
    c2i_ibuf(&local_28);
    uVar8 = (uint)local_28;
    uVar6 = 0;
    goto LAB_0017f31a;
  }
  bVar1 = *pbVar7;
  if (bVar1 == 0) {
LAB_0017f2e8:
    if ((bVar1 & 0x80) == (pbVar7[1] & 0x80)) {
      ERR_put_error(0xd,0xe2,0xdd,"crypto/asn1/a_int.c",0xbb);
      return 0;
    }
    uVar3 = 1;
  }
  else if (bVar1 == 0xff) {
    if (param_4 < 0x22) {
      uVar3 = 0;
      iVar11 = 1;
    }
    else {
      uVar3 = 0;
      pbVar9 = pbVar7 + 0x23;
      iVar12 = 1;
      do {
        iVar11 = iVar12 + 0x20;
        uVar6 = iVar12 + 0x21;
        HintPreloadData(pbVar9);
        uVar3 = uVar3 | (byte)(pbVar9[-0xb] |
                               pbVar9[-0xc] |
                               pbVar9[-0xd] |
                               pbVar9[-0xe] |
                               pbVar9[-0xf] |
                               pbVar9[-0x10] |
                               pbVar9[-0x11] |
                               pbVar9[-0x1d] |
                               pbVar9[-0x1e] |
                               pbVar9[-0x1f] | pbVar9[-0x20] | pbVar9[-0x22] | pbVar9[-0x21] |
                               pbVar9[-0x1c] | pbVar9[-0x1b] | pbVar9[-0x1a] | pbVar9[-0x19] |
                               pbVar9[-0x18] | pbVar9[-0x17] | pbVar9[-0x16] | pbVar9[-0x15] |
                               pbVar9[-0x14] | pbVar9[-0x13] | pbVar9[-0x12] | pbVar9[-10] |
                               pbVar9[-9] | pbVar9[-8] | pbVar9[-7] | pbVar9[-6] | pbVar9[-5] |
                               pbVar9[-4] | pbVar9[-3]);
        pbVar9 = pbVar9 + 0x20;
        iVar12 = iVar11;
      } while (uVar6 < param_4 - 0x1f);
    }
    pbVar9 = pbVar7 + iVar11;
    do {
      pbVar10 = pbVar9 + 1;
      uVar3 = uVar3 | *pbVar9;
      pbVar9 = pbVar10;
    } while ((uint)((int)pbVar10 - (int)pbVar7) < param_4);
    if (uVar3 != 0) goto LAB_0017f2e8;
  }
  else {
    uVar3 = 0;
  }
  uVar3 = param_4 - uVar3;
  if (8 < uVar3) {
    ERR_put_error(0xd,0x65,0xdf,"crypto/asn1/a_int.c",0x267);
    return 0;
  }
  c2i_ibuf(&local_28,param_2,pbVar7,param_4);
  uVar8 = (uint)local_28;
  uVar6 = 0;
  if (uVar3 != 1) {
    uVar6 = 0;
    uVar8 = (uint)CONCAT11(local_28,local_27);
    if (uVar3 != 2) {
      uVar6 = 0;
      uVar2 = CONCAT21(CONCAT11(local_28,local_27),local_26);
      uVar8 = (uint)uVar2;
      if (uVar3 != 3) {
        uVar8 = CONCAT31(uVar2,local_25);
        uVar6 = 0;
        if (uVar3 != 4) {
          uVar4 = uVar8 << 8;
          uVar6 = (uint)local_28;
          uVar8 = local_24 | uVar4;
          if (uVar3 != 5) {
            uVar5 = uVar8 << 8;
            uVar6 = uVar6 << 8 | uVar4 >> 0x18;
            uVar8 = local_23 | uVar5;
            if (uVar3 != 6) {
              uVar4 = uVar8 << 8;
              uVar6 = uVar6 << 8 | uVar5 >> 0x18;
              uVar8 = local_22 | uVar4;
              if (uVar3 == 8) {
                uVar6 = uVar6 << 8 | uVar4 >> 0x18;
                uVar8 = (uint)local_21 | uVar8 << 8;
              }
            }
          }
        }
      }
    }
  }
LAB_0017f31a:
  *param_1 = uVar8;
  param_1[1] = uVar6;
  return 1;
}

