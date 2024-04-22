
undefined4 int_def_cb(char *param_1,size_t param_2,uint *param_3)

{
  int iVar1;
  
  if (param_1 != (char *)0x0) {
    iVar1 = strncmp(param_1,DAT_000a74d8,param_2);
    if (iVar1 == 0) {
      *param_3 = ~(~(*param_3 >> 0x10) << 0x10);
      return 1;
    }
    iVar1 = strncmp(param_1,DAT_000a74dc,param_2);
    if (iVar1 == 0) {
      *param_3 = *param_3 | 1;
      return 1;
    }
    iVar1 = strncmp(param_1,DAT_000a74e0,param_2);
    if (iVar1 == 0) {
      *param_3 = *param_3 | 2;
      return 1;
    }
    iVar1 = strncmp(param_1,DAT_000a74e4,param_2);
    if (iVar1 == 0) {
      *param_3 = *param_3 | 0x10;
      return 1;
    }
    iVar1 = strncmp(param_1,DAT_000a74e8,param_2);
    if (iVar1 == 0) {
      *param_3 = *param_3 | 0x20;
      return 1;
    }
    iVar1 = strncmp(param_1,DAT_000a74ec,param_2);
    if (iVar1 == 0) {
      *param_3 = *param_3 | 4;
      return 1;
    }
    iVar1 = strncmp(param_1,DAT_000a74f0,param_2);
    if (iVar1 == 0) {
      *param_3 = *param_3 | 8;
      return 1;
    }
    iVar1 = strncmp(param_1,DAT_000a74f4,param_2);
    if (iVar1 == 0) {
      *param_3 = *param_3 | 0x40;
      return 1;
    }
    iVar1 = strncmp(param_1,DAT_000a74f8,param_2);
    if (iVar1 == 0) {
      *param_3 = *param_3 | 0x80;
      return 1;
    }
    iVar1 = strncmp(param_1,DAT_000a74fc,param_2);
    if (iVar1 == 0) {
      *param_3 = *param_3 | 0x600;
      return 1;
    }
    iVar1 = strncmp(param_1,DAT_000a7500,param_2);
    if (iVar1 == 0) {
      *param_3 = *param_3 | 0x200;
      return 1;
    }
    iVar1 = strncmp(param_1,DAT_000a7504,param_2);
    if (iVar1 == 0) {
      *param_3 = *param_3 | 0x400;
      return 1;
    }
  }
  return 0;
}

