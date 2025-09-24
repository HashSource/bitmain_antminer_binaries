
uint equal_nocase(byte *param_1,uint param_2,byte *param_3,uint param_4,uint param_5)

{
  byte bVar1;
  byte *pbVar2;
  uint uVar3;
  uint uVar4;
  
  if ((param_5 & 0x8000) == 0) {
    if (param_4 != param_2) {
      return 0;
    }
  }
  else {
    if ((param_4 < param_2) && (*param_1 != 0)) {
      uVar4 = (param_5 << 0x1b) >> 0x1f;
      uVar3 = uVar4;
      if (*param_1 != 0x2e) {
        uVar3 = 0;
      }
      if (uVar3 == 0) {
        param_1 = param_1 + 1;
        while (param_2 = param_2 - 1, param_4 != param_2) {
          uVar3 = uVar4;
          if (*param_1 != 0x2e) {
            uVar3 = 0;
          }
          if (*param_1 == 0) {
            return 0;
          }
          param_1 = param_1 + 1;
          if (uVar3 != 0) {
            return 0;
          }
        }
        goto LAB_0017949a;
      }
    }
    if (param_4 != param_2) {
      return 0;
    }
  }
LAB_0017949a:
  if (param_2 == 0) {
    return 1;
  }
  uVar3 = (uint)*param_1;
  bVar1 = *param_3;
  if (uVar3 != 0) {
    pbVar2 = param_1 + param_2;
    do {
      uVar4 = (uint)bVar1;
      param_1 = param_1 + 1;
      if (uVar3 != uVar4) {
        if (uVar3 - 0x41 < 0x1a) {
          uVar3 = uVar3 + 0x20 & 0xff;
          if (uVar4 - 0x41 < 0x1a) goto LAB_001794e2;
        }
        else {
          if (0x19 < uVar4 - 0x41) {
            return 0;
          }
LAB_001794e2:
          uVar4 = uVar4 + 0x20 & 0xff;
        }
        if (uVar4 != uVar3) {
          return 0;
        }
      }
      if (pbVar2 == param_1) {
        return 1;
      }
      uVar3 = (uint)*param_1;
      param_3 = param_3 + 1;
      bVar1 = *param_3;
    } while (uVar3 != 0);
  }
  return uVar3;
}

