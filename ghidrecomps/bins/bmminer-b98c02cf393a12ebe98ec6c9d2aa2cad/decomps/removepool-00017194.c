
void removepool(undefined4 param_1,undefined4 param_2,char *param_3,undefined4 param_4)

{
  undefined4 uVar1;
  long lVar2;
  int iVar3;
  int iVar4;
  
  if (total_pools == 0) {
    message(param_1,8,0);
    return;
  }
  if ((param_3 == (char *)0x0) || (*param_3 == '\0')) {
    iVar3 = 0;
    lVar2 = 0;
    uVar1 = 0x19;
  }
  else {
    lVar2 = strtol(param_3,(char **)0x0,10);
    if ((lVar2 < 0) || (total_pools <= lVar2)) {
      message(param_1,0x1a,lVar2,0);
      return;
    }
    if (total_pools < 2) {
      iVar3 = 0;
      uVar1 = 0x42;
    }
    else {
      iVar4 = *(int *)(pools + lVar2 * 4);
      iVar3 = current_pool();
      if (iVar4 == iVar3) {
        switch_pools(0);
      }
      iVar3 = current_pool();
      if (iVar4 == iVar3) {
        iVar3 = 0;
        uVar1 = 0x43;
      }
      else {
        *(undefined4 *)(iVar4 + 100) = 0;
        iVar3 = escape_string(*(undefined4 *)(iVar4 + 0xa4),param_4);
        if (iVar3 != *(int *)(iVar4 + 0xa4)) {
          remove_pool(iVar4);
          message(param_1,0x44,lVar2,iVar3,param_4);
                    /* WARNING: Could not recover jumptable at 0x00012060. Too many branches */
                    /* WARNING: Treating indirect jump as call */
          (*(code *)PTR_LAB_0007ce68)(iVar3);
          return;
        }
        remove_pool(iVar4);
        uVar1 = 0x44;
      }
    }
  }
  message(param_1,uVar1,lVar2,iVar3);
  return;
}

