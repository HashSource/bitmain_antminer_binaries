
uint ocsp_helper(undefined4 param_1,int param_2,int param_3)

{
  uint uVar1;
  
  if (param_3 == 0) {
    return 1;
  }
  uVar1 = *(uint *)(param_2 + 0x80);
  if (((uVar1 & 2) != 0) && ((*(uint *)(param_2 + 0x84) & 4) == 0)) {
    return 0;
  }
  if ((int)(uVar1 << 0x1f) < 0) {
    uVar1 = (uVar1 << 0x1b) >> 0x1f;
  }
  else if ((uVar1 & 0x2040) == 0x2040) {
    uVar1 = 3;
  }
  else if ((uVar1 & 2) == 0) {
    if ((int)(uVar1 << 0x1c) < 0) {
      if ((*(uint *)(param_2 + 0x8c) & 7) == 0) {
        uVar1 = 0;
      }
      else {
        uVar1 = 5;
      }
    }
    else {
      uVar1 = 0;
    }
  }
  else {
    uVar1 = 4;
  }
  return uVar1;
}

