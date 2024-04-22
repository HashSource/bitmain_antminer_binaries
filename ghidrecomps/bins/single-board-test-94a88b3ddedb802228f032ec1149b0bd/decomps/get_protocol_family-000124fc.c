
undefined4 get_protocol_family(uint param_1)

{
  if (param_1 != 0x2000) {
    if (0x2000 < param_1) {
      if (param_1 == 0x100000) {
        return 0x100000;
      }
      if (param_1 < 0x100001) {
        if (param_1 == 0x10000) {
          return 0x10000;
        }
        if (param_1 < 0x10001) {
          if ((param_1 == 0x4000) || (param_1 == 0x8000)) {
            return 0x4000;
          }
        }
        else {
          if (param_1 == 0x40000) {
            return 0x40000;
          }
          if (param_1 == 0x80000) {
            return 0x80000;
          }
          if (param_1 == 0x20000) {
            return 0x10000;
          }
        }
      }
      else {
        if (param_1 == 0x1000000) {
          return 0x100000;
        }
        if (param_1 < 0x1000001) {
          if (param_1 == 0x400000) {
            return 0x400000;
          }
          if (param_1 == 0x800000) {
            return 0x80000;
          }
          if (param_1 == 0x200000) {
            return 0x200000;
          }
        }
        else {
          if ((param_1 == 0x4000000) || (param_1 == 0x8000000)) {
            return 0x4000000;
          }
          if (param_1 == 0x2000000) {
            return 0x2000000;
          }
        }
      }
      return 0;
    }
    if (param_1 == 0x40) {
      return 0x40;
    }
    if (param_1 < 0x41) {
      if (param_1 != 4) {
        if (param_1 < 5) {
          if (1 < param_1 - 1) {
            return 0;
          }
          return 1;
        }
        if (param_1 == 0x10) {
          return 0x10;
        }
        if (param_1 == 0x20) {
          return 0x20;
        }
        if (param_1 != 8) {
          return 0;
        }
      }
    }
    else {
      if (param_1 == 0x200) {
        return 0x200;
      }
      if (param_1 < 0x201) {
        if ((param_1 != 0x80) && (param_1 != 0x100)) {
          return 0;
        }
      }
      else {
        if (param_1 == 0x800) {
          return 0x800;
        }
        if (param_1 != 0x1000) {
          if (param_1 != 0x400) {
            return 0;
          }
          return 0x400;
        }
      }
    }
  }
  return 0x1000;
}

