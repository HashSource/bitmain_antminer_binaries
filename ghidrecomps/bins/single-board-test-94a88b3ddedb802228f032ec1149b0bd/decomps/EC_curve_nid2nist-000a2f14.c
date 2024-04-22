
undefined4 EC_curve_nid2nist(int param_1)

{
  int iVar1;
  
  if (param_1 == 0x2d3) {
    iVar1 = 0;
  }
  else if (param_1 == 0x2d7) {
    iVar1 = 1;
  }
  else if (param_1 == 0x2da) {
    iVar1 = 2;
  }
  else if (param_1 == 0x2dc) {
    iVar1 = 3;
  }
  else if (param_1 == 0x2de) {
    iVar1 = 4;
  }
  else if (param_1 == 0x2d1) {
    iVar1 = 5;
  }
  else if (param_1 == 0x2d6) {
    iVar1 = 6;
  }
  else if (param_1 == 0x2d9) {
    iVar1 = 7;
  }
  else if (param_1 == 0x2db) {
    iVar1 = 8;
  }
  else if (param_1 == 0x2dd) {
    iVar1 = 9;
  }
  else if (param_1 == 0x199) {
    iVar1 = 10;
  }
  else if (param_1 == 0x2c9) {
    iVar1 = 0xb;
  }
  else if (param_1 == 0x19f) {
    iVar1 = 0xc;
  }
  else if (param_1 == 0x2cb) {
    iVar1 = 0xd;
  }
  else {
    if (param_1 != 0x2cc) {
      return 0;
    }
    iVar1 = 0xe;
  }
  return *(undefined4 *)(DAT_000a2fc4 + iVar1 * 8 + 0x510);
}

