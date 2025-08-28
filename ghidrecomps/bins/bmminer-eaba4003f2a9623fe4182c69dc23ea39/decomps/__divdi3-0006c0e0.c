
undefined8 __divdi3(uint param_1,uint param_2,uint param_3,uint param_4)

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
  uint unaff_r7;
  uint uVar10;
  uint uVar11;
  bool bVar12;
  bool bVar13;
  bool bVar14;
  
  if ((int)param_2 < 0) {
    bVar12 = param_1 != 0;
    param_1 = -param_1;
    param_2 = -param_2 - (uint)bVar12;
    uVar8 = 0xffffffff;
  }
  else {
    uVar8 = 0;
  }
  if ((int)param_4 < 0) {
    uVar8 = ~uVar8;
    bVar12 = param_3 != 0;
    param_3 = -param_3;
    param_4 = -param_4 - (uint)bVar12;
  }
  if (param_4 == 0) {
    if (param_2 < param_3) {
      iVar5 = LZCOUNT(param_3);
      if (iVar5 != 0) {
        uVar4 = param_1 >> (0x20U - iVar5 & 0xff);
        param_3 = param_3 << iVar5;
        param_1 = param_1 << iVar5;
        param_2 = uVar4 | param_2 << iVar5;
      }
      uVar10 = param_3 >> 0x10;
      __aeabi_uidivmod(param_2,uVar10);
      iVar2 = __aeabi_uidiv(param_2,uVar10);
      uVar4 = (param_3 & 0xffff) * iVar2;
      uVar6 = param_1 >> 0x10 | extraout_r1 << 0x10;
      iVar5 = iVar2;
      if (uVar6 <= uVar4 && uVar4 - uVar6 != 0) {
        bVar12 = CARRY4(uVar6,param_3);
        uVar6 = uVar6 + param_3;
        iVar5 = iVar2 + -1;
        if ((!bVar12) && (uVar6 <= uVar4 && uVar4 - uVar6 != 0)) {
          iVar5 = iVar2 + -2;
          uVar6 = uVar6 + param_3;
        }
      }
      __aeabi_uidivmod(uVar6 - uVar4,uVar10);
      uVar9 = param_1 & 0xffff | extraout_r1_00 << 0x10;
      uVar6 = __aeabi_uidiv(uVar6 - uVar4,uVar10);
      uVar10 = (param_3 & 0xffff) * uVar6;
      uVar4 = uVar6;
      if (uVar9 <= uVar10 && uVar10 - uVar9 != 0) {
        uVar4 = uVar6 - 1;
        if ((!CARRY4(uVar9,param_3)) &&
           (uVar9 + param_3 <= uVar10 && uVar10 - (uVar9 + param_3) != 0)) {
          uVar4 = uVar6 - 2;
        }
      }
      unaff_r7 = 0;
      uVar4 = uVar4 | iVar5 << 0x10;
    }
    else {
      if (param_3 == 0) {
        param_3 = __aeabi_uidiv(1,0);
      }
      iVar5 = LZCOUNT(param_3);
      if (iVar5 == 0) {
        uVar9 = param_3 >> 0x10;
        uVar11 = param_3 & 0xffff;
        iVar5 = param_2 - param_3;
        unaff_r7 = 1;
      }
      else {
        param_3 = param_3 << iVar5;
        uVar4 = param_2 >> (0x20U - iVar5 & 0xff);
        uVar6 = param_1 >> (0x20U - iVar5 & 0xff);
        uVar9 = param_3 >> 0x10;
        uVar11 = param_3 & 0xffff;
        param_1 = param_1 << iVar5;
        uVar6 = uVar6 | param_2 << iVar5;
        __aeabi_uidivmod(uVar4,uVar9);
        iVar2 = __aeabi_uidiv(uVar4,uVar9);
        uVar4 = uVar11 * iVar2;
        uVar10 = uVar6 >> 0x10 | extraout_r1_03 << 0x10;
        iVar5 = iVar2;
        if (uVar10 <= uVar4 && uVar4 - uVar10 != 0) {
          bVar12 = CARRY4(uVar10,param_3);
          uVar10 = uVar10 + param_3;
          iVar5 = iVar2 + -1;
          if ((!bVar12) && (uVar10 <= uVar4 && uVar4 - uVar10 != 0)) {
            iVar5 = iVar2 + -2;
            uVar10 = uVar10 + param_3;
          }
        }
        __aeabi_uidivmod(uVar10 - uVar4,uVar9);
        uVar10 = __aeabi_uidiv(uVar10 - uVar4,uVar9);
        uVar7 = uVar11 * uVar10;
        uVar6 = uVar6 & 0xffff | extraout_r1_04 << 0x10;
        uVar4 = uVar10;
        if (uVar6 <= uVar7 && uVar7 - uVar6 != 0) {
          bVar12 = CARRY4(uVar6,param_3);
          uVar6 = uVar6 + param_3;
          uVar4 = uVar10 - 1;
          if ((!bVar12) && (uVar6 <= uVar7 && uVar7 - uVar6 != 0)) {
            uVar4 = uVar10 - 2;
            uVar6 = uVar6 + param_3;
          }
        }
        unaff_r7 = uVar4 | iVar5 << 0x10;
        iVar5 = uVar6 - uVar7;
      }
      __aeabi_uidivmod(iVar5,uVar9);
      iVar2 = __aeabi_uidiv(iVar5,uVar9);
      uVar4 = uVar11 * iVar2;
      uVar6 = param_1 >> 0x10 | extraout_r1_01 << 0x10;
      iVar5 = iVar2;
      if (uVar6 <= uVar4 && uVar4 - uVar6 != 0) {
        bVar12 = CARRY4(uVar6,param_3);
        uVar6 = uVar6 + param_3;
        iVar5 = iVar2 + -1;
        if ((!bVar12) && (uVar6 <= uVar4 && uVar4 - uVar6 != 0)) {
          iVar5 = iVar2 + -2;
          uVar6 = uVar6 + param_3;
        }
      }
      __aeabi_uidivmod(uVar6 - uVar4,uVar9);
      uVar6 = __aeabi_uidiv(uVar6 - uVar4,uVar9);
      uVar11 = uVar11 * uVar6;
      uVar10 = param_1 & 0xffff | extraout_r1_02 << 0x10;
      uVar4 = uVar6;
      if (uVar10 <= uVar11 && uVar11 - uVar10 != 0) {
        uVar4 = uVar6 - 1;
        if ((!CARRY4(uVar10,param_3)) &&
           (uVar10 + param_3 <= uVar11 && uVar11 - (uVar10 + param_3) != 0)) {
          uVar4 = uVar6 - 2;
        }
      }
      uVar4 = uVar4 | iVar5 << 0x10;
    }
  }
  else if (param_2 < param_4) {
    unaff_r7 = 0;
    uVar4 = unaff_r7;
  }
  else {
    iVar5 = LZCOUNT(param_4);
    if (iVar5 == 0) {
      bVar13 = param_4 < param_2;
      bVar12 = param_4 == param_2;
      if (!bVar13) {
        bVar12 = param_3 == param_1;
      }
      bVar14 = param_3 < param_1;
      if ((!bVar13 && !bVar14) && !bVar12) {
        unaff_r7 = 0;
      }
      if ((bVar13 || bVar14) || bVar12) {
        param_1 = 1;
        unaff_r7 = 0;
      }
      uVar4 = param_1;
      if ((!bVar13 && !bVar14) && !bVar12) {
        uVar4 = unaff_r7;
      }
    }
    else {
      uVar6 = 0x20 - iVar5;
      uVar4 = param_2 >> (uVar6 & 0xff);
      uVar11 = param_3 >> (uVar6 & 0xff) | param_4 << iVar5;
      uVar10 = uVar11 >> 0x10;
      uVar9 = param_1 >> (uVar6 & 0xff) | param_2 << iVar5;
      __aeabi_uidivmod(uVar4,uVar10);
      iVar3 = __aeabi_uidiv(uVar4,uVar10);
      uVar4 = (uVar11 & 0xffff) * iVar3;
      uVar6 = uVar9 >> 0x10 | extraout_r1_05 << 0x10;
      iVar2 = iVar3;
      if (uVar6 <= uVar4 && uVar4 - uVar6 != 0) {
        bVar12 = CARRY4(uVar6,uVar11);
        uVar6 = uVar6 + uVar11;
        iVar2 = iVar3 + -1;
        if ((!bVar12) && (uVar6 <= uVar4 && uVar4 - uVar6 != 0)) {
          iVar2 = iVar3 + -2;
          uVar6 = uVar6 + uVar11;
        }
      }
      __aeabi_uidivmod(uVar6 - uVar4,uVar10);
      uVar6 = __aeabi_uidiv(uVar6 - uVar4,uVar10);
      uVar7 = (uVar11 & 0xffff) * uVar6;
      uVar10 = uVar9 & 0xffff | extraout_r1_06 << 0x10;
      uVar4 = uVar6;
      if (uVar10 <= uVar7 && uVar7 - uVar10 != 0) {
        bVar12 = CARRY4(uVar10,uVar11);
        uVar10 = uVar10 + uVar11;
        uVar4 = uVar6 - 1;
        if ((!bVar12) && (uVar10 <= uVar7 && uVar7 - uVar10 != 0)) {
          uVar4 = uVar6 - 2;
          uVar10 = uVar10 + uVar11;
        }
      }
      uVar4 = uVar4 | iVar2 << 0x10;
      lVar1 = (ulonglong)uVar4 * (ulonglong)(param_3 << iVar5);
      uVar6 = (uint)((ulonglong)lVar1 >> 0x20);
      if (uVar6 <= uVar10 - uVar7) {
        unaff_r7 = (uint)(uVar10 - uVar7 == uVar6);
        if ((uint)lVar1 <= param_1 << iVar5) {
          unaff_r7 = 0;
        }
        if (unaff_r7 == 0) goto LAB_0006c1a6;
      }
      uVar4 = uVar4 - 1;
      unaff_r7 = 0;
    }
  }
LAB_0006c1a6:
  if (uVar8 != 0) {
    bVar12 = uVar4 != 0;
    uVar4 = -uVar4;
    unaff_r7 = -unaff_r7 - (uint)bVar12;
  }
  return CONCAT44(unaff_r7,uVar4);
}

