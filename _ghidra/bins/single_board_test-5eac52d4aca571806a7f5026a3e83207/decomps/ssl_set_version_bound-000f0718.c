
undefined4 ssl_set_version_bound(int param_1,int param_2,int *param_3)

{
  if (param_2 == 0) {
    *param_3 = 0;
    return 1;
  }
  if (param_2 < 0xff01 && (param_2 == 0x100 || 0xfefc < param_2)) {
    if (param_1 == 0x10000) {
      if (param_2 - 0x300U < 5) goto LAB_000f0756;
    }
    else if (param_1 == 0x1ffff) {
LAB_000f0756:
      *param_3 = param_2;
      return 1;
    }
  }
  else {
    if (4 < param_2 - 0x300U) {
      return 0;
    }
    if (param_1 == 0x10000) goto LAB_000f0756;
  }
  return 1;
}

