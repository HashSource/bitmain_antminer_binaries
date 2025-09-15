
undefined4 utf8_check_full(byte *param_1,uint param_2,uint *param_3)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  bool bVar4;
  
  uVar3 = (uint)*param_1;
  if (param_2 == 2) {
    uVar3 = uVar3 & 0x1f;
  }
  else if (param_2 == 3) {
    uVar3 = uVar3 & 0xf;
  }
  else {
    if (param_2 != 4) {
      return 0;
    }
    uVar3 = uVar3 & 7;
  }
  uVar1 = (uint)param_1[1];
  if ((uVar1 ^ 0x80) < 0x40) {
    param_1 = param_1 + 1;
    uVar2 = 1;
    do {
      uVar2 = uVar2 + 1;
      uVar3 = (uVar1 & 0x3f) + uVar3 * 0x40;
      if (param_2 <= uVar2) {
        if (0x10ffff < (int)uVar3) {
          return 0;
        }
        if (uVar3 - 0xd800 < 0x800) {
          return 0;
        }
        bVar4 = uVar3 == 0x7f;
        if ((int)uVar3 < 0x80) {
          bVar4 = param_2 == 2;
        }
        if (bVar4) {
          return 0;
        }
        if ((int)uVar3 < 0x800 && param_2 == 3) {
          return 0;
        }
        if ((int)uVar3 < 0x10000 && param_2 == 4) {
          return 0;
        }
        if (param_3 == (uint *)0x0) {
          return 1;
        }
        *param_3 = uVar3;
        return 1;
      }
      param_1 = param_1 + 1;
      uVar1 = (uint)*param_1;
    } while ((uVar1 ^ 0x80) < 0x40);
  }
  return 0;
}

