
uint check_purpose_ssl_client(undefined4 param_1,int param_2,int param_3)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = *(uint *)(param_2 + 0x80);
  if ((-1 < (int)(uVar2 << 0x1d)) || (uVar1 = *(uint *)(param_2 + 0x88) & 2, uVar1 != 0)) {
    if (param_3 == 0) {
      if (((int)(uVar2 << 0x1e) < 0) && ((*(uint *)(param_2 + 0x84) & 0x88) == 0)) {
        return 0;
      }
      if ((int)(uVar2 << 0x1c) < 0) {
        uVar1 = (uint)(*(int *)(param_2 + 0x8c) << 0x18) >> 0x1f;
      }
      else {
        uVar1 = 1;
      }
    }
    else if (((uVar2 & 2) == 0) || (uVar1 = *(uint *)(param_2 + 0x84) & 4, uVar1 != 0)) {
      if ((int)(uVar2 << 0x1f) < 0) {
        uVar1 = (uVar2 << 0x1b) >> 0x1f;
      }
      else if ((uVar2 & 0x2040) == 0x2040) {
        uVar1 = 3;
      }
      else if ((uVar2 & 2) == 0) {
        if (-1 < (int)(uVar2 << 0x1c)) {
          return 0;
        }
        if ((*(uint *)(param_2 + 0x8c) & 7) == 0) {
          return 0;
        }
        if ((*(uint *)(param_2 + 0x8c) & 4) == 0) {
          uVar1 = 0;
        }
        else {
          uVar1 = 5;
        }
      }
      else {
        uVar1 = 4;
      }
    }
  }
  return uVar1;
}

