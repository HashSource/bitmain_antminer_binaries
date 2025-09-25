
undefined4 ASN1_ENUMERATED_get_int64(uint *param_1,uint *param_2)

{
  byte bVar1;
  uint3 uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  byte *pbVar7;
  uint uVar8;
  uint uVar9;
  bool bVar10;
  
  if (param_2 == (uint *)0x0) {
    ERR_put_error(0xd,0xe3,0x43,"crypto/asn1/a_int.c",0x142);
    return 0;
  }
  if ((param_2[1] & 0xfffffeff) != 10) {
    ERR_put_error(0xd,0xe3,0xe1,"crypto/asn1/a_int.c",0x146);
    return 0;
  }
  uVar3 = *param_2;
  if (8 < uVar3) {
    ERR_put_error(0xd,0xe1,0xdf,"crypto/asn1/a_int.c",0xd5);
    return 0;
  }
  pbVar7 = (byte *)param_2[2];
  if (pbVar7 == (byte *)0x0) {
    return 0;
  }
  uVar6 = param_2[1] & 0x100;
  if (uVar3 == 0) {
    uVar4 = 0;
    uVar5 = 0;
    if (uVar6 == 0) goto LAB_0017ad96;
    uVar4 = 0;
    uVar5 = 0;
  }
  else {
    bVar1 = *pbVar7;
    uVar4 = (uint)bVar1;
    uVar5 = 0;
    if (uVar3 != 1) {
      uVar5 = 0;
      uVar4 = (uint)CONCAT11(bVar1,pbVar7[1]);
      if (uVar3 != 2) {
        uVar5 = 0;
        uVar2 = CONCAT21(CONCAT11(bVar1,pbVar7[1]),pbVar7[2]);
        uVar4 = (uint)uVar2;
        if (uVar3 != 3) {
          uVar5 = 0;
          uVar4 = CONCAT31(uVar2,pbVar7[3]);
          if (uVar3 != 4) {
            uVar8 = uVar4 << 8;
            uVar5 = (uint)bVar1;
            uVar4 = pbVar7[4] | uVar8;
            if (uVar3 != 5) {
              uVar9 = uVar4 << 8;
              uVar5 = uVar5 << 8 | uVar8 >> 0x18;
              uVar4 = pbVar7[5] | uVar9;
              if (uVar3 != 6) {
                uVar8 = uVar4 << 8;
                uVar5 = uVar5 << 8 | uVar9 >> 0x18;
                uVar4 = pbVar7[6] | uVar8;
                if (uVar3 == 8) {
                  uVar5 = uVar5 << 8 | uVar8 >> 0x18;
                  uVar4 = (uint)pbVar7[7] | uVar4 << 8;
                }
              }
            }
          }
        }
      }
    }
    if (uVar6 == 0) {
      if ((int)uVar5 < 0) {
        ERR_put_error(0xd,0xe0,0xdf,"crypto/asn1/a_int.c",0x110);
        return 0;
      }
LAB_0017ad96:
      *param_1 = uVar4;
      param_1[1] = uVar5;
      return 1;
    }
    if ((int)uVar5 < 0) {
      if (uVar5 != 0x80000000 || uVar4 != 0) {
        ERR_put_error(0xd,0xe0,0xe0,"crypto/asn1/a_int.c",0x109);
        return 0;
      }
    }
    else {
      bVar10 = uVar4 != 0;
      uVar4 = -uVar4;
      uVar5 = -uVar5 - (uint)bVar10;
    }
  }
  *param_1 = uVar4;
  param_1[1] = uVar5;
  return 1;
}

