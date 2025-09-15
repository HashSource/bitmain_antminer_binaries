
uint pickoneauth(uint *param_1)

{
  uint uVar1;
  uint uVar2;
  bool bVar3;
  
  uVar1 = *param_1 & param_1[2];
  if ((int)(uVar1 << 0x1d) < 0) {
    uVar1 = 1;
    param_1[1] = 4;
  }
  else if ((int)(uVar1 << 0x1e) < 0) {
    uVar1 = 1;
    param_1[1] = 2;
  }
  else if ((int)(uVar1 << 0x1c) < 0) {
    uVar1 = 1;
    param_1[1] = 8;
  }
  else {
    uVar2 = uVar1 << 0x1a;
    if ((int)uVar2 < 0) {
      uVar1 = 1;
      param_1[1] = 0x20;
    }
    else {
      bVar3 = (uVar1 & 1) != 0;
      if (!bVar3) {
        uVar2 = 0x40000000;
      }
      uVar1 = (uint)bVar3;
      if (bVar3) {
        param_1[1] = uVar1;
      }
      if (!bVar3) {
        param_1[1] = uVar2;
      }
    }
  }
  param_1[2] = 0;
  return uVar1;
}

