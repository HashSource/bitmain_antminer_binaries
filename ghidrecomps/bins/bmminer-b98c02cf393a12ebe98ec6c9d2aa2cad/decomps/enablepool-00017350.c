
void enablepool(undefined4 param_1,undefined4 param_2,char *param_3)

{
  long lVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  if (total_pools == 0) {
    message(param_1,8,0);
    return;
  }
  if ((param_3 != (char *)0x0) && (*param_3 != '\0')) {
    lVar1 = strtol(param_3,(char **)0x0,10);
    if ((-1 < lVar1) && (lVar1 < total_pools)) {
      iVar3 = *(int *)(pools + lVar1 * 4);
      if (*(int *)(iVar3 + 100) != 1) {
        iVar4 = *(int *)(iVar3 + 4);
        *(undefined4 *)(iVar3 + 100) = 1;
        iVar2 = current_pool();
        if (iVar4 < *(int *)(iVar2 + 4)) {
          switch_pools(iVar3);
        }
        message(param_1,0x2f,lVar1,0);
        return;
      }
      message(param_1,0x31,lVar1,0);
      return;
    }
    message(param_1,0x1a,lVar1,0);
    return;
  }
  message(param_1,0x19,0);
  return;
}

