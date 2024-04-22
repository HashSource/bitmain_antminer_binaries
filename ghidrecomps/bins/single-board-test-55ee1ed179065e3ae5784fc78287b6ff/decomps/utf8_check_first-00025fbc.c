
undefined4 utf8_check_first(byte param_1)

{
  undefined4 uVar1;
  
  if ((char)param_1 < '\0') {
    if (((char)param_1 < '\0') && (param_1 < 0xc0)) {
      uVar1 = 0;
    }
    else if ((param_1 == 0xc0) || (param_1 == 0xc1)) {
      uVar1 = 0;
    }
    else if ((param_1 < 0xc2) || (0xdf < param_1)) {
      if ((param_1 < 0xe0) || (0xef < param_1)) {
        if ((param_1 < 0xf0) || (0xf4 < param_1)) {
          uVar1 = 0;
        }
        else {
          uVar1 = 4;
        }
      }
      else {
        uVar1 = 3;
      }
    }
    else {
      uVar1 = 2;
    }
  }
  else {
    uVar1 = 1;
  }
  return uVar1;
}

