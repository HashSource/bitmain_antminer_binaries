
undefined4 tls1_ec_nid2curve_id(int param_1)

{
  if (param_1 == 0x2d3) {
    return 3;
  }
  if (param_1 < 0x2d4) {
    if (param_1 == 0x2c8) {
      return 0x14;
    }
    if (param_1 < 0x2c9) {
      if (param_1 == 0x2c4) {
        return 0xf;
      }
      if (0x2c4 < param_1) {
        if (param_1 == 0x2c6) {
          return 0x11;
        }
        if (0x2c6 < param_1) {
          return 0x12;
        }
        return 0x10;
      }
      if (param_1 == 0x199) {
        return 0x13;
      }
      if (param_1 == 0x19f) {
        return 0x17;
      }
    }
    else {
      if (param_1 == 0x2cb) {
        return 0x18;
      }
      if (param_1 < 0x2cc) {
        if (param_1 == 0x2c9) {
          return 0x15;
        }
        if (param_1 == 0x2ca) {
          return 0x16;
        }
      }
      else {
        if (param_1 == 0x2d1) {
          return 1;
        }
        if (0x2d1 < param_1) {
          return 2;
        }
        if (param_1 == 0x2cc) {
          return 0x19;
        }
      }
    }
  }
  else {
    if (param_1 == 0x2da) {
      return 10;
    }
    if (param_1 < 0x2db) {
      if (param_1 == 0x2d6) {
        return 6;
      }
      if (0x2d6 < param_1) {
        if (param_1 == 0x2d8) {
          return 8;
        }
        if (0x2d8 < param_1) {
          return 9;
        }
        return 7;
      }
      if (param_1 == 0x2d4) {
        return 4;
      }
      if (param_1 == 0x2d5) {
        return 5;
      }
    }
    else {
      if (param_1 == 0x2de) {
        return 0xe;
      }
      if (param_1 < 0x2df) {
        if (param_1 == 0x2dc) {
          return 0xc;
        }
        if (0x2dc < param_1) {
          return 0xd;
        }
        return 0xb;
      }
      if (param_1 == 0x3a3) {
        return 0x1b;
      }
      if (param_1 == 0x3a5) {
        return 0x1c;
      }
      if (param_1 == 0x39f) {
        return 0x1a;
      }
    }
  }
  return 0;
}

