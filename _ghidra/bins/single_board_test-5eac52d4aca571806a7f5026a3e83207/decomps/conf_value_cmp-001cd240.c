
int conf_value_cmp(undefined4 *param_1,undefined4 *param_2)

{
  int iVar1;
  
  if (((char *)*param_1 == (char *)*param_2) ||
     (iVar1 = strcmp((char *)*param_1,(char *)*param_2), iVar1 == 0)) {
    if ((char *)param_1[1] == (char *)0x0) {
      iVar1 = param_2[1];
      if (iVar1 != 0) {
        iVar1 = 1;
      }
      return -iVar1;
    }
    if ((char *)param_2[1] != (char *)0x0) {
      iVar1 = strcmp((char *)param_1[1],(char *)param_2[1]);
      return iVar1;
    }
    iVar1 = 1;
  }
  return iVar1;
}

