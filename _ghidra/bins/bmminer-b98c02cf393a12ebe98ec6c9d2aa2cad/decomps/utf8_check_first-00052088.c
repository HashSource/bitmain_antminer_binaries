
undefined4 utf8_check_first(uint param_1)

{
  undefined4 uVar1;
  
  if (-1 < (int)(param_1 << 0x18)) {
    return 1;
  }
  if ((param_1 ^ 0x80) < 0x42) {
    return 0;
  }
  if ((param_1 + 0x3e & 0xff) < 0x1e) {
    return 2;
  }
  if (0xf < (param_1 + 0x20 & 0xff)) {
    if ((param_1 + 0x10 & 0xff) < 5) {
      uVar1 = 4;
    }
    else {
      uVar1 = 0;
    }
    return uVar1;
  }
  return 3;
}

