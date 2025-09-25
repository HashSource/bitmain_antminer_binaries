
undefined4 ASN1_INTEGER_get_uint64(uint *param_1,uint *param_2)

{
  byte bVar1;
  uint3 uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  byte *pbVar6;
  undefined4 uVar7;
  uint uVar8;
  uint uVar9;
  
  if (param_2 == (uint *)0x0) {
    ERR_put_error(0xd,0xe6,0x43,"crypto/asn1/a_int.c",0x165);
    uVar7 = 0;
  }
  else {
    if ((param_2[1] & 0xfffffeff) != 2) {
      ERR_put_error(0xd,0xe6,0xe1,"crypto/asn1/a_int.c",0x169);
      return 0;
    }
    if ((param_2[1] & 0x100) != 0) {
      ERR_put_error(0xd,0xe6,0xe2,"crypto/asn1/a_int.c",0x16d);
      return 0;
    }
    uVar3 = *param_2;
    uVar7 = 0;
    if (uVar3 < 9) {
      pbVar6 = (byte *)param_2[2];
      if (pbVar6 != (byte *)0x0) {
        if (uVar3 == 0) {
          uVar4 = 0;
          uVar5 = 0;
        }
        else {
          bVar1 = *pbVar6;
          uVar4 = (uint)bVar1;
          uVar5 = 0;
          if (uVar3 != 1) {
            uVar5 = 0;
            uVar4 = (uint)CONCAT11(bVar1,pbVar6[1]);
            if (uVar3 != 2) {
              uVar5 = 0;
              uVar2 = CONCAT21(CONCAT11(bVar1,pbVar6[1]),pbVar6[2]);
              uVar4 = (uint)uVar2;
              if (uVar3 != 3) {
                uVar4 = CONCAT31(uVar2,pbVar6[3]);
                uVar5 = 0;
                if (uVar3 != 4) {
                  uVar8 = uVar4 << 8;
                  uVar5 = (uint)bVar1;
                  uVar4 = pbVar6[4] | uVar8;
                  if (uVar3 != 5) {
                    uVar9 = uVar4 << 8;
                    uVar5 = uVar5 << 8 | uVar8 >> 0x18;
                    uVar4 = pbVar6[5] | uVar9;
                    if (uVar3 != 6) {
                      uVar8 = uVar4 << 8;
                      uVar5 = uVar5 << 8 | uVar9 >> 0x18;
                      uVar4 = pbVar6[6] | uVar8;
                      if (uVar3 == 8) {
                        uVar5 = uVar5 << 8 | uVar8 >> 0x18;
                        uVar4 = (uint)pbVar6[7] | uVar4 << 8;
                      }
                    }
                  }
                }
              }
            }
          }
        }
        uVar7 = 1;
        *param_1 = uVar4;
        param_1[1] = uVar5;
      }
    }
    else {
      ERR_put_error(0xd,0xe1,0xdf,"crypto/asn1/a_int.c",0xd5);
    }
  }
  return uVar7;
}

