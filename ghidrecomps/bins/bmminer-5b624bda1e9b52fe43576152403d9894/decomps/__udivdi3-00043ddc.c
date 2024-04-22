
undefined8 __udivdi3(uint param_1,uint param_2,uint param_3,uint param_4)

{
  longlong lVar1;
  bool bVar2;
  int iVar3;
  int iVar4;
  int extraout_r1;
  int extraout_r1_00;
  int extraout_r1_01;
  int extraout_r1_02;
  int extraout_r1_03;
  int extraout_r1_04;
  int extraout_r1_05;
  int extraout_r1_06;
  uint uVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  bool bVar12;
  bool bVar13;
  
  if (param_4 == 0) {
    if (param_2 < param_3) {
      iVar6 = LZCOUNT(param_3);
      if (iVar6 != 0) {
        uVar5 = param_1 >> (0x20U - iVar6 & 0xff);
        param_3 = param_3 << iVar6;
        param_1 = param_1 << iVar6;
        param_2 = uVar5 | param_2 << iVar6;
      }
      uVar8 = param_3 >> 0x10;
      __aeabi_uidivmod(param_2,uVar8);
      iVar3 = __aeabi_uidiv(param_2,uVar8);
      uVar5 = (param_3 & 0xffff) * iVar3;
      uVar7 = param_1 >> 0x10 | extraout_r1 << 0x10;
      iVar6 = iVar3;
      if (uVar7 <= uVar5 && uVar5 - uVar7 != 0) {
        bVar12 = CARRY4(uVar7,param_3);
        uVar7 = uVar7 + param_3;
        iVar6 = iVar3 + -1;
        if ((bVar12 == false) && (uVar7 <= uVar5 && uVar5 - uVar7 != 0)) {
          iVar6 = iVar3 + -2;
          uVar7 = uVar7 + param_3;
        }
      }
      __aeabi_uidivmod(uVar7 - uVar5,uVar8);
      uVar9 = param_1 & 0xffff | extraout_r1_00 << 0x10;
      uVar5 = __aeabi_uidiv(uVar7 - uVar5,uVar8);
      uVar8 = (param_3 & 0xffff) * uVar5;
      uVar7 = uVar5;
      if (uVar9 <= uVar8 && uVar8 - uVar9 != 0) {
        uVar7 = uVar5 - 1;
        if ((CARRY4(uVar9,param_3) == false) &&
           (uVar9 + param_3 <= uVar8 && uVar8 - (uVar9 + param_3) != 0)) {
          uVar7 = uVar5 - 2;
        }
      }
      uVar5 = 0;
      uVar7 = uVar7 | iVar6 << 0x10;
    }
    else {
      if (param_3 == 0) {
        param_3 = __aeabi_uidiv(1,0);
      }
      iVar6 = LZCOUNT(param_3);
      if (iVar6 == 0) {
        uVar9 = param_3 >> 0x10;
        uVar11 = param_3 & 0xffff;
        iVar6 = param_2 - param_3;
        uVar5 = 1;
      }
      else {
        param_3 = param_3 << iVar6;
        uVar5 = param_2 >> (0x20U - iVar6 & 0xff);
        uVar8 = param_1 >> (0x20U - iVar6 & 0xff);
        uVar9 = param_3 >> 0x10;
        uVar11 = param_3 & 0xffff;
        param_1 = param_1 << iVar6;
        uVar8 = param_2 << iVar6 | uVar8;
        __aeabi_uidivmod(uVar5,uVar9);
        iVar3 = __aeabi_uidiv(uVar5,uVar9);
        uVar5 = uVar11 * iVar3;
        uVar7 = uVar8 >> 0x10 | extraout_r1_05 << 0x10;
        iVar6 = iVar3;
        if (uVar7 <= uVar5 && uVar5 - uVar7 != 0) {
          bVar12 = CARRY4(uVar7,param_3);
          uVar7 = uVar7 + param_3;
          iVar6 = iVar3 + -1;
          if ((bVar12 == false) && (uVar7 <= uVar5 && uVar5 - uVar7 != 0)) {
            iVar6 = iVar3 + -2;
            uVar7 = uVar7 + param_3;
          }
        }
        __aeabi_uidivmod(uVar7 - uVar5,uVar9);
        uVar7 = __aeabi_uidiv(uVar7 - uVar5,uVar9);
        uVar10 = uVar11 * uVar7;
        uVar8 = uVar8 & 0xffff | extraout_r1_06 << 0x10;
        uVar5 = uVar7;
        if (uVar8 <= uVar10 && uVar10 - uVar8 != 0) {
          bVar12 = CARRY4(uVar8,param_3);
          uVar8 = uVar8 + param_3;
          uVar5 = uVar7 - 1;
          if ((bVar12 == false) && (uVar8 <= uVar10 && uVar10 - uVar8 != 0)) {
            uVar5 = uVar7 - 2;
            uVar8 = uVar8 + param_3;
          }
        }
        uVar5 = uVar5 | iVar6 << 0x10;
        iVar6 = uVar8 - uVar10;
      }
      __aeabi_uidivmod(iVar6,uVar9);
      iVar3 = __aeabi_uidiv(iVar6,uVar9);
      uVar7 = uVar11 * iVar3;
      uVar8 = param_1 >> 0x10 | extraout_r1_01 << 0x10;
      iVar6 = iVar3;
      if (uVar8 <= uVar7 && uVar7 - uVar8 != 0) {
        bVar12 = CARRY4(uVar8,param_3);
        uVar8 = uVar8 + param_3;
        iVar6 = iVar3 + -1;
        if ((bVar12 == false) && (uVar8 <= uVar7 && uVar7 - uVar8 != 0)) {
          iVar6 = iVar3 + -2;
          uVar8 = uVar8 + param_3;
        }
      }
      __aeabi_uidivmod(uVar8 - uVar7,uVar9);
      uVar10 = param_1 & 0xffff | extraout_r1_02 << 0x10;
      uVar8 = __aeabi_uidiv(uVar8 - uVar7,uVar9);
      uVar11 = uVar11 * uVar8;
      uVar7 = uVar8;
      if (uVar10 <= uVar11 && uVar11 - uVar10 != 0) {
        uVar7 = uVar8 - 1;
        if ((CARRY4(uVar10,param_3) == false) &&
           (uVar10 + param_3 <= uVar11 && uVar11 - (uVar10 + param_3) != 0)) {
          uVar7 = uVar8 - 2;
        }
      }
      uVar7 = uVar7 | iVar6 << 0x10;
    }
  }
  else if (param_2 < param_4) {
    uVar5 = 0;
    uVar7 = uVar5;
  }
  else {
    iVar6 = LZCOUNT(param_4);
    if (iVar6 == 0) {
      bVar13 = param_4 < param_2;
      bVar12 = param_4 == param_2;
      if (!bVar13) {
        bVar12 = param_3 == param_1;
      }
      bVar2 = param_3 < param_1;
      uVar5 = param_1;
      if ((!bVar13 && !bVar2) && !bVar12) {
        uVar5 = 0;
      }
      if ((bVar13 || bVar2) || bVar12) {
        param_1 = 1;
        uVar5 = 0;
      }
      uVar7 = param_1;
      if ((!bVar13 && !bVar2) && !bVar12) {
        uVar7 = uVar5;
      }
    }
    else {
      uVar5 = 0x20 - iVar6;
      uVar8 = param_2 >> (uVar5 & 0xff);
      uVar9 = param_3 >> (uVar5 & 0xff) | param_4 << iVar6;
      uVar11 = uVar9 >> 0x10;
      uVar7 = param_2 << iVar6 | param_1 >> (uVar5 & 0xff);
      __aeabi_uidivmod(uVar8,uVar11);
      iVar4 = __aeabi_uidiv(uVar8,uVar11);
      uVar5 = (uVar9 & 0xffff) * iVar4;
      uVar8 = uVar7 >> 0x10 | extraout_r1_03 << 0x10;
      iVar3 = iVar4;
      if (uVar8 <= uVar5 && uVar5 - uVar8 != 0) {
        bVar12 = CARRY4(uVar8,uVar9);
        uVar8 = uVar8 + uVar9;
        iVar3 = iVar4 + -1;
        if ((bVar12 == false) && (uVar8 <= uVar5 && uVar5 - uVar8 != 0)) {
          iVar3 = iVar4 + -2;
          uVar8 = uVar8 + uVar9;
        }
      }
      __aeabi_uidivmod(uVar8 - uVar5,uVar11);
      uVar5 = __aeabi_uidiv(uVar8 - uVar5,uVar11);
      uVar11 = (uVar9 & 0xffff) * uVar5;
      uVar8 = uVar7 & 0xffff | extraout_r1_04 << 0x10;
      uVar7 = uVar5;
      if (uVar8 <= uVar11 && uVar11 - uVar8 != 0) {
        bVar12 = CARRY4(uVar8,uVar9);
        uVar8 = uVar8 + uVar9;
        uVar7 = uVar5 - 1;
        if ((bVar12 == false) && (uVar8 <= uVar11 && uVar11 - uVar8 != 0)) {
          uVar7 = uVar5 - 2;
          uVar8 = uVar8 + uVar9;
        }
      }
      uVar7 = uVar7 | iVar3 << 0x10;
      lVar1 = (ulonglong)uVar7 * (ulonglong)(param_3 << iVar6);
      uVar5 = (uint)((ulonglong)lVar1 >> 0x20);
      if (uVar5 <= uVar8 - uVar11) {
        uVar5 = (uint)(uVar8 - uVar11 == uVar5);
        if ((uint)lVar1 <= param_1 << iVar6) {
          uVar5 = 0;
        }
        if (uVar5 == 0) goto LAB_00043e8a;
      }
      uVar7 = uVar7 - 1;
      uVar5 = 0;
    }
  }
LAB_00043e8a:
  return CONCAT44(uVar5,uVar7);
}

