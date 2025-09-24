
uint check_purpose_smime_encrypt(undefined4 param_1,int param_2,int param_3)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = *(uint *)(param_2 + 0x80);
  if ((-1 < (int)(uVar2 << 0x1d)) || (uVar1 = *(uint *)(param_2 + 0x88) & 4, uVar1 != 0)) {
    if (param_3 == 0) {
      if (((int)(uVar2 << 0x1c) < 0) && ((*(uint *)(param_2 + 0x8c) & 0x20) == 0)) {
        if (-1 < (int)(*(uint *)(param_2 + 0x8c) << 0x18)) {
          return 0;
        }
        uVar1 = 2;
      }
      else {
        uVar1 = 1;
      }
      if (-1 < (int)(uVar2 << 0x1e)) {
        return uVar1;
      }
      if ((*(uint *)(param_2 + 0x84) & 0x20) == 0) {
        uVar1 = 0;
      }
      return uVar1;
    }
    if (((uVar2 & 2) == 0) || (uVar1 = *(uint *)(param_2 + 0x84) & 4, uVar1 != 0)) {
      if ((int)(uVar2 << 0x1f) < 0) {
        return (uVar2 << 0x1b) >> 0x1f;
      }
      if ((uVar2 & 0x2040) == 0x2040) {
        return 3;
      }
      if ((uVar2 & 2) != 0) {
        return 4;
      }
      if ((-1 < (int)(uVar2 << 0x1c)) || ((*(uint *)(param_2 + 0x8c) & 7) == 0)) {
        return 0;
      }
      if ((*(uint *)(param_2 + 0x8c) & 2) == 0) {
        uVar1 = 0;
      }
      else {
        uVar1 = 5;
      }
    }
  }
  return uVar1;
}

