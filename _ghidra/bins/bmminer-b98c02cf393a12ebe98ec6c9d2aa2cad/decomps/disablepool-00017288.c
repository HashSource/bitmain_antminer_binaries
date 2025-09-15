
void disablepool(undefined4 param_1,undefined4 param_2,char *param_3)

{
  long lVar1;
  int iVar2;
  int iVar3;
  
  if (total_pools == 0) {
    message(param_1,8,0);
    return;
  }
  if ((param_3 == (char *)0x0) || (*param_3 == '\0')) {
    message(param_1,0x19,0);
    return;
  }
  lVar1 = strtol(param_3,(char **)0x0,10);
  if ((lVar1 < 0) || (total_pools <= lVar1)) {
    message(param_1,0x1a,lVar1,0);
    return;
  }
  iVar3 = *(int *)(pools + lVar1 * 4);
  if (*(int *)(iVar3 + 100) == 0) {
    message(param_1,0x32,lVar1);
    return;
  }
  if (1 < enabled_pools) {
    *(undefined4 *)(iVar3 + 100) = 0;
    iVar2 = current_pool();
    if (iVar3 == iVar2) {
      switch_pools(0);
    }
    message(param_1,0x30,lVar1,0);
    return;
  }
  message(param_1,0x33,lVar1,0);
  return;
}

