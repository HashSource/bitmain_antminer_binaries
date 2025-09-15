
undefined4 tftp_translate_code(int param_1)

{
  if (param_1 == -100) {
    return 0;
  }
  if (param_1 == 2) {
    return 0x45;
  }
  if (param_1 < 3) {
    if (param_1 == -0x62) {
      return 7;
    }
    if (param_1 == -0x62 || param_1 + 0x62 < 0 != SCARRY4(param_1,0x62)) {
      if (param_1 == -99) {
        return 0x1c;
      }
    }
    else {
      if (param_1 == 0) {
        return 0x47;
      }
      if (param_1 == 1) {
        return 0x44;
      }
    }
  }
  else {
    if (param_1 == 5) {
      return 0x48;
    }
    if (param_1 < 6) {
      if (param_1 == 3) {
        return 0x46;
      }
      if (param_1 == 4) {
        return 0x47;
      }
    }
    else {
      if (param_1 == 6) {
        return 0x49;
      }
      if (param_1 == 7) {
        return 0x4a;
      }
    }
  }
  return 0x2a;
}

