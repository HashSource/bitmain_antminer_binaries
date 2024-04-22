
uint ocsp_helper(undefined4 param_1,int param_2,int param_3)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = 1;
  if (param_3 != 0) {
    uVar2 = *(uint *)(param_2 + 0x28);
    if (((uVar2 & 2) == 0) || ((*(uint *)(param_2 + 0x2c) & 4) != 0)) {
      if ((int)(uVar2 << 0x1f) < 0) {
        uVar1 = (uVar2 << 0x1b) >> 0x1f;
      }
      else if ((uVar2 & 0x2040) == 0x2040) {
        uVar1 = 3;
      }
      else {
        uVar1 = 4;
        if ((uVar2 & 2) == 0) {
          if ((int)(uVar2 << 0x1c) < 0) {
            if ((*(uint *)(param_2 + 0x34) & 7) == 0) {
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
      }
    }
    else {
      uVar1 = 0;
    }
  }
  return uVar1;
}

