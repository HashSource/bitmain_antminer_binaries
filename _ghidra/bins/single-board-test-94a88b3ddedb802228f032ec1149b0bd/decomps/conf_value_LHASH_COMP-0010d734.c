
int conf_value_LHASH_COMP(undefined4 *param_1,undefined4 *param_2)

{
  int iVar1;
  
  if (((char *)*param_1 == (char *)*param_2) ||
     (iVar1 = strcmp((char *)*param_1,(char *)*param_2), iVar1 == 0)) {
    if (param_1[1] == 0) {
      if (param_2[1] == 0) {
        iVar1 = 0;
      }
      else {
        iVar1 = -1;
      }
      return iVar1;
    }
    if (param_2[1] != 0) {
      iVar1 = (*(code *)(undefined *)0x0)();
      return iVar1;
    }
    iVar1 = 1;
  }
  return iVar1;
}

