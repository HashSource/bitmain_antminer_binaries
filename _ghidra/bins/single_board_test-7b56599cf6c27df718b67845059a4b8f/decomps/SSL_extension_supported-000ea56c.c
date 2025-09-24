
undefined4 SSL_extension_supported(uint param_1)

{
  if (param_1 < 0x18) {
    if (param_1 < 0x15) {
      if (param_1 < 0xf) {
        if (((param_1 < 10) && (1 < param_1)) && (param_1 != 5)) {
          return 0;
        }
      }
      else if ((param_1 != 0x10) && (param_1 != 0x12)) {
        return 0;
      }
    }
  }
  else if (param_1 != 0x2f) {
    if (param_1 < 0x30) {
      if (param_1 != 0x23) {
        if (param_1 < 0x23) {
          return 0;
        }
        if (4 < param_1 - 0x29) {
          return 0;
        }
      }
    }
    else if (param_1 != 0x33) {
      if (param_1 < 0x34) {
        if (param_1 != 0x31) {
          return 0;
        }
      }
      else if ((param_1 != 0x3374) && (param_1 != 0xff01)) {
        return 0;
      }
    }
  }
  return 1;
}

