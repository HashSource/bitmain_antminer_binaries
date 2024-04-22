
undefined8 __udivmoddi4(uint param_1,uint param_2,uint param_3,uint param_4,uint *param_5)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  int iVar10;
  uint uVar11;
  bool bVar12;
  
  bVar12 = param_4 <= param_2;
  if (param_2 == param_4) {
    bVar12 = param_3 <= param_1;
  }
  if (bVar12) {
    if (param_4 == 0) {
      iVar10 = LZCOUNT(param_3) + 0x20;
    }
    else {
      iVar10 = LZCOUNT(param_4);
    }
    if (param_2 == 0) {
      iVar4 = LZCOUNT(param_1) + 0x20;
    }
    else {
      iVar4 = LZCOUNT(param_2);
    }
    uVar11 = iVar10 - iVar4;
    uVar9 = uVar11 - 0x20;
    uVar8 = 0x20 - uVar11;
    uVar2 = param_3 << (uVar11 & 0xff);
    uVar7 = param_4 << (uVar11 & 0xff) | param_3 << (uVar9 & 0xff) | param_3 >> (uVar8 & 0xff);
    bVar12 = uVar7 <= param_2;
    if (param_2 == uVar7) {
      bVar12 = uVar2 <= param_1;
    }
    if (bVar12) {
      bVar12 = param_1 < uVar2;
      param_1 = param_1 - uVar2;
      uVar3 = 1 << (uVar11 & 0xff);
      uVar5 = 1 << (uVar9 & 0xff) | 1U >> (uVar8 & 0xff);
      param_2 = param_2 - (uVar7 + bVar12);
    }
    else {
      uVar3 = 0;
      uVar5 = uVar3;
    }
    if (uVar11 != 0) {
      uVar1 = uVar7 >> 1;
      uVar2 = (uint)((byte)uVar7 & 1) << 0x1f | uVar2 >> 1;
      uVar7 = uVar11;
      do {
        while( true ) {
          bVar12 = uVar1 <= param_2;
          if (param_2 == uVar1) {
            bVar12 = uVar2 <= param_1;
          }
          if (bVar12) break;
          bVar12 = CARRY4(param_1,param_1);
          param_1 = param_1 * 2;
          param_2 = param_2 * 2 + (uint)bVar12;
          uVar7 = uVar7 - 1;
          uVar6 = param_2;
          if (uVar7 == 0) goto LAB_00097ad0;
        }
        bVar12 = param_1 < uVar2;
        uVar6 = param_1 - uVar2;
        param_1 = uVar6 * 2 + 1;
        param_2 = (param_2 - (uVar1 + bVar12)) * 2 + (uint)CARRY4(uVar6,uVar6) +
                  (uint)(0xfffffffe < uVar6 * 2);
        uVar7 = uVar7 - 1;
        uVar6 = param_2;
      } while (uVar7 != 0);
LAB_00097ad0:
      param_2 = uVar6 >> (uVar11 & 0xff);
      bVar12 = CARRY4(uVar3,param_1);
      uVar7 = uVar3 + param_1;
      param_1 = param_1 >> (uVar11 & 0xff) | uVar6 << (uVar8 & 0xff) | uVar6 >> (uVar9 & 0xff);
      uVar2 = param_1 << (uVar11 & 0xff);
      uVar3 = uVar7 - uVar2;
      uVar5 = (uVar5 + uVar6 + (uint)bVar12) -
              ((param_2 << (uVar11 & 0xff) | param_1 << (uVar9 & 0xff) | param_1 >> (uVar8 & 0xff))
              + (uint)(uVar7 < uVar2));
    }
  }
  else {
    uVar3 = 0;
    uVar5 = uVar3;
  }
  if (param_5 == (uint *)0x0) {
    return CONCAT44(uVar5,uVar3);
  }
  *param_5 = param_1;
  param_5[1] = param_2;
  return CONCAT44(uVar5,uVar3);
}

