
undefined8 __udivdi3(uint param_1,uint param_2,uint param_3,uint param_4)

{
  longlong lVar1;
  int iVar2;
  int iVar3;
  int extraout_r1;
  int extraout_r1_00;
  int extraout_r1_01;
  int extraout_r1_02;
  int extraout_r1_03;
  int extraout_r1_04;
  int extraout_r1_05;
  int extraout_r1_06;
  uint uVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  bool bVar11;
  bool bVar12;
  bool bVar13;
  
  if (param_4 == 0) {
    if (param_2 < param_3) {
      iVar5 = LZCOUNT(param_3);
      if (iVar5 != 0) {
        uVar4 = param_1 >> (0x20U - iVar5 & 0xff);
        param_3 = param_3 << iVar5;
        param_1 = param_1 << iVar5;
        param_2 = uVar4 | param_2 << iVar5;
      }
      uVar7 = param_3 >> 0x10;
      __aeabi_uidivmod(param_2,uVar7);
      iVar2 = __aeabi_uidiv(param_2,uVar7);
      uVar4 = (param_3 & 0xffff) * iVar2;
      uVar6 = param_1 >> 0x10 | extraout_r1 << 0x10;
      iVar5 = iVar2;
      if (uVar6 <= uVar4 && uVar4 - uVar6 != 0) {
        bVar11 = CARRY4(uVar6,param_3);
        uVar6 = uVar6 + param_3;
        iVar5 = iVar2 + -1;
        if ((!bVar11) && (uVar6 <= uVar4 && uVar4 - uVar6 != 0)) {
          iVar5 = iVar2 + -2;
          uVar6 = uVar6 + param_3;
        }
      }
      __aeabi_uidivmod(uVar6 - uVar4,uVar7);
      uVar8 = param_1 & 0xffff | extraout_r1_00 << 0x10;
      uVar4 = __aeabi_uidiv(uVar6 - uVar4,uVar7);
      uVar7 = (param_3 & 0xffff) * uVar4;
      uVar6 = uVar4;
      if (uVar8 <= uVar7 && uVar7 - uVar8 != 0) {
        uVar6 = uVar4 - 1;
        if ((!CARRY4(uVar8,param_3)) && (uVar8 + param_3 <= uVar7 && uVar7 - (uVar8 + param_3) != 0)
           ) {
          uVar6 = uVar4 - 2;
        }
      }
      uVar4 = 0;
      uVar6 = uVar6 | iVar5 << 0x10;
    }
    else {
      if (param_3 == 0) {
        param_3 = __aeabi_uidiv(1,0);
      }
      iVar5 = LZCOUNT(param_3);
      if (iVar5 == 0) {
        uVar8 = param_3 >> 0x10;
        uVar10 = param_3 & 0xffff;
        iVar5 = param_2 - param_3;
        uVar4 = 1;
      }
      else {
        param_3 = param_3 << iVar5;
        uVar4 = param_2 >> (0x20U - iVar5 & 0xff);
        uVar7 = param_1 >> (0x20U - iVar5 & 0xff);
        uVar8 = param_3 >> 0x10;
        uVar10 = param_3 & 0xffff;
        param_1 = param_1 << iVar5;
        uVar7 = param_2 << iVar5 | uVar7;
        __aeabi_uidivmod(uVar4,uVar8);
        iVar2 = __aeabi_uidiv(uVar4,uVar8);
        uVar4 = uVar10 * iVar2;
        uVar6 = uVar7 >> 0x10 | extraout_r1_05 << 0x10;
        iVar5 = iVar2;
        if (uVar6 <= uVar4 && uVar4 - uVar6 != 0) {
          bVar11 = CARRY4(uVar6,param_3);
          uVar6 = uVar6 + param_3;
          iVar5 = iVar2 + -1;
          if ((!bVar11) && (uVar6 <= uVar4 && uVar4 - uVar6 != 0)) {
            iVar5 = iVar2 + -2;
            uVar6 = uVar6 + param_3;
          }
        }
        __aeabi_uidivmod(uVar6 - uVar4,uVar8);
        uVar6 = __aeabi_uidiv(uVar6 - uVar4,uVar8);
        uVar9 = uVar10 * uVar6;
        uVar7 = uVar7 & 0xffff | extraout_r1_06 << 0x10;
        uVar4 = uVar6;
        if (uVar7 <= uVar9 && uVar9 - uVar7 != 0) {
          bVar11 = CARRY4(uVar7,param_3);
          uVar7 = uVar7 + param_3;
          uVar4 = uVar6 - 1;
          if ((!bVar11) && (uVar7 <= uVar9 && uVar9 - uVar7 != 0)) {
            uVar4 = uVar6 - 2;
            uVar7 = uVar7 + param_3;
          }
        }
        uVar4 = uVar4 | iVar5 << 0x10;
        iVar5 = uVar7 - uVar9;
      }
      __aeabi_uidivmod(iVar5,uVar8);
      iVar2 = __aeabi_uidiv(iVar5,uVar8);
      uVar6 = uVar10 * iVar2;
      uVar7 = param_1 >> 0x10 | extraout_r1_01 << 0x10;
      iVar5 = iVar2;
      if (uVar7 <= uVar6 && uVar6 - uVar7 != 0) {
        bVar11 = CARRY4(uVar7,param_3);
        uVar7 = uVar7 + param_3;
        iVar5 = iVar2 + -1;
        if ((!bVar11) && (uVar7 <= uVar6 && uVar6 - uVar7 != 0)) {
          iVar5 = iVar2 + -2;
          uVar7 = uVar7 + param_3;
        }
      }
      __aeabi_uidivmod(uVar7 - uVar6,uVar8);
      uVar9 = param_1 & 0xffff | extraout_r1_02 << 0x10;
      uVar7 = __aeabi_uidiv(uVar7 - uVar6,uVar8);
      uVar10 = uVar10 * uVar7;
      uVar6 = uVar7;
      if (uVar9 <= uVar10 && uVar10 - uVar9 != 0) {
        uVar6 = uVar7 - 1;
        if ((!CARRY4(uVar9,param_3)) &&
           (uVar9 + param_3 <= uVar10 && uVar10 - (uVar9 + param_3) != 0)) {
          uVar6 = uVar7 - 2;
        }
      }
      uVar6 = uVar6 | iVar5 << 0x10;
    }
  }
  else if (param_2 < param_4) {
    uVar4 = 0;
    uVar6 = uVar4;
  }
  else {
    iVar5 = LZCOUNT(param_4);
    if (iVar5 == 0) {
      bVar12 = param_4 < param_2;
      bVar11 = param_4 == param_2;
      if (!bVar12) {
        bVar11 = param_3 == param_1;
      }
      bVar13 = param_3 < param_1;
      uVar4 = param_1;
      if ((!bVar12 && !bVar13) && !bVar11) {
        uVar4 = 0;
      }
      if ((bVar12 || bVar13) || bVar11) {
        param_1 = 1;
        uVar4 = 0;
      }
      uVar6 = param_1;
      if ((!bVar12 && !bVar13) && !bVar11) {
        uVar6 = uVar4;
      }
    }
    else {
      uVar4 = 0x20 - iVar5;
      uVar7 = param_2 >> (uVar4 & 0xff);
      uVar8 = param_3 >> (uVar4 & 0xff) | param_4 << iVar5;
      uVar10 = uVar8 >> 0x10;
      uVar6 = param_2 << iVar5 | param_1 >> (uVar4 & 0xff);
      __aeabi_uidivmod(uVar7,uVar10);
      iVar3 = __aeabi_uidiv(uVar7,uVar10);
      uVar4 = (uVar8 & 0xffff) * iVar3;
      uVar7 = uVar6 >> 0x10 | extraout_r1_03 << 0x10;
      iVar2 = iVar3;
      if (uVar7 <= uVar4 && uVar4 - uVar7 != 0) {
        bVar11 = CARRY4(uVar7,uVar8);
        uVar7 = uVar7 + uVar8;
        iVar2 = iVar3 + -1;
        if ((!bVar11) && (uVar7 <= uVar4 && uVar4 - uVar7 != 0)) {
          iVar2 = iVar3 + -2;
          uVar7 = uVar7 + uVar8;
        }
      }
      __aeabi_uidivmod(uVar7 - uVar4,uVar10);
      uVar4 = __aeabi_uidiv(uVar7 - uVar4,uVar10);
      uVar10 = (uVar8 & 0xffff) * uVar4;
      uVar7 = uVar6 & 0xffff | extraout_r1_04 << 0x10;
      uVar6 = uVar4;
      if (uVar7 <= uVar10 && uVar10 - uVar7 != 0) {
        bVar11 = CARRY4(uVar7,uVar8);
        uVar7 = uVar7 + uVar8;
        uVar6 = uVar4 - 1;
        if ((!bVar11) && (uVar7 <= uVar10 && uVar10 - uVar7 != 0)) {
          uVar6 = uVar4 - 2;
          uVar7 = uVar7 + uVar8;
        }
      }
      uVar6 = uVar6 | iVar2 << 0x10;
      lVar1 = (ulonglong)uVar6 * (ulonglong)(param_3 << iVar5);
      uVar4 = (uint)((ulonglong)lVar1 >> 0x20);
      if (uVar4 <= uVar7 - uVar10) {
        uVar4 = (uint)(uVar7 - uVar10 == uVar4);
        if ((uint)lVar1 <= param_1 << iVar5) {
          uVar4 = 0;
        }
        if (uVar4 == 0) goto LAB_0006c4e2;
      }
      uVar6 = uVar6 - 1;
      uVar4 = 0;
    }
  }
LAB_0006c4e2:
  return CONCAT44(uVar4,uVar6);
}

