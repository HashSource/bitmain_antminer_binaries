
int SSL_CONF_cmd_argv(uint *param_1,int *param_2,int *param_3)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  
  if (param_2 == (int *)0x0) {
    iVar1 = *(int *)*param_3;
    if (iVar1 == 0) {
      return 0;
    }
    iVar2 = ((int *)*param_3)[1];
    *param_1 = *param_1 & 0xfffffffd | 1;
    iVar1 = SSL_CONF_cmd(param_1,iVar1,iVar2);
    if (0 < iVar1) {
      *param_3 = *param_3 + iVar1 * 4;
      return iVar1;
    }
  }
  else {
    if (*param_2 < 1) {
      return 0;
    }
    iVar1 = *(int *)*param_3;
    if (iVar1 == 0) {
      return 0;
    }
    if (*param_2 == 1) {
      uVar3 = *param_1;
      iVar2 = 0;
    }
    else {
      uVar3 = *param_1;
      iVar2 = ((int *)*param_3)[1];
    }
    *param_1 = uVar3 & 0xfffffffd | 1;
    iVar1 = SSL_CONF_cmd(param_1,iVar1,iVar2);
    if (0 < iVar1) {
      *param_3 = *param_3 + iVar1 * 4;
      *param_2 = *param_2 - iVar1;
      return iVar1;
    }
  }
  if (iVar1 == -2) {
    return 0;
  }
  if (iVar1 == 0) {
    iVar1 = -1;
  }
  return iVar1;
}

