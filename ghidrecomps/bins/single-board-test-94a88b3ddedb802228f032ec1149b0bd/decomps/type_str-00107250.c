
undefined4 type_str(uint param_1,uint *param_2)

{
  char *pcVar1;
  uint uVar2;
  
  uVar2 = *param_2;
  if ((int)(uVar2 << 0x1e) < 0) {
    if ((0x7f < param_1) ||
       ((((0x19 < param_1 - 0x61 && (0x19 < param_1 - 0x41)) && (9 < param_1 - 0x30)) &&
        ((param_1 != 0x20 && (pcVar1 = strchr(DAT_001072c0,param_1), pcVar1 == (char *)0x0)))))) {
      uVar2 = uVar2 & 0xfffffffd;
      goto LAB_0010728a;
    }
  }
  else {
LAB_0010728a:
    if (((int)(uVar2 << 0x1b) < 0) && (0x7f < param_1)) {
      uVar2 = uVar2 & 0xffffffef;
    }
  }
  if (((int)(uVar2 << 0x1d) < 0) && (0xff < param_1)) {
    uVar2 = uVar2 & 0xfffffffb;
  }
  if ((int)(uVar2 << 0x14) < 0) {
    if (param_1 < 0x10000) goto LAB_001072b2;
    uVar2 = uVar2 & 0xfffff7ff;
  }
  if (uVar2 == 0) {
    return 0xffffffff;
  }
LAB_001072b2:
  *param_2 = uVar2;
  return 1;
}

