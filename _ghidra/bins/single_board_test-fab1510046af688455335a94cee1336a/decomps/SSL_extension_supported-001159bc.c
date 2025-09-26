
undefined4 SSL_extension_supported(uint param_1)

{
  if (param_1 < 0x11) {
    if (((param_1 < 10) && (param_1 != 0)) && (param_1 != 5)) {
      return 0;
    }
  }
  else if (param_1 != 0x23) {
    if (param_1 < 0x24) {
      if (param_1 != 0x15) {
        return 0;
      }
    }
    else if ((param_1 != 0x3374) && (param_1 != 0xff01)) {
      return 0;
    }
  }
  return 1;
}

