
bool equal_case(char *param_1,uint param_2,void *param_3,uint param_4,uint param_5)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  
  if ((param_5 & 0x8000) == 0) {
    if (param_4 != param_2) {
      return false;
    }
  }
  else {
    if ((param_4 < param_2) && (*param_1 != '\0')) {
      uVar3 = (param_5 << 0x1b) >> 0x1f;
      uVar2 = uVar3;
      if (*param_1 != '.') {
        uVar2 = 0;
      }
      if (uVar2 == 0) {
        param_1 = param_1 + 1;
        while (param_2 = param_2 - 1, param_4 != param_2) {
          uVar2 = uVar3;
          if (*param_1 != '.') {
            uVar2 = 0;
          }
          if (*param_1 == '\0') {
            return false;
          }
          param_1 = param_1 + 1;
          if (uVar2 != 0) {
            return false;
          }
        }
        goto LAB_00175346;
      }
    }
    if (param_4 != param_2) {
      return false;
    }
  }
LAB_00175346:
  iVar1 = memcmp(param_1,param_3,param_2);
  return iVar1 == 0;
}

