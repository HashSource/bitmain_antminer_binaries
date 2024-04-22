
undefined4 pop3_endofresp(int param_1,char *param_2,uint param_3,undefined4 *param_4)

{
  int iVar1;
  
  if ((3 < param_3) && (iVar1 = memcmp(DAT_00051378,param_2,4), iVar1 == 0)) {
    *param_4 = 0x2d;
    return 1;
  }
  if (*(int *)(param_1 + 0x3f8) == 2) {
    if ((param_3 != 0) && (*param_2 == '.')) {
LAB_0005136e:
      *param_4 = 0x2b;
      return 1;
    }
  }
  else {
    if (param_3 < 3) {
      if (param_3 == 0) {
        return 0;
      }
    }
    else {
      iVar1 = memcmp(DAT_0005137c,param_2,3);
      if (iVar1 == 0) goto LAB_0005136e;
    }
    if (*param_2 != '+') {
      return 0;
    }
  }
  *param_4 = 0x2a;
  return 1;
}

