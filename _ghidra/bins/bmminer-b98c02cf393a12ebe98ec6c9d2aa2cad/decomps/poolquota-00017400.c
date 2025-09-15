
void poolquota(undefined4 param_1,undefined4 param_2,char *param_3)

{
  char *pcVar1;
  long lVar2;
  int iVar3;
  
  if (total_pools == 0) {
    message(param_1,8,0);
    return;
  }
  if ((param_3 == (char *)0x0) || (*param_3 == '\0')) {
    message(param_1,0x19,0);
    return;
  }
  pcVar1 = strchr(param_3,0x2c);
  if (pcVar1 == (char *)0x0) {
    message(param_1,0x56,0,param_3);
    return;
  }
  *pcVar1 = '\0';
  lVar2 = strtol(param_3,(char **)0x0,10);
  if ((-1 < lVar2) && (lVar2 < total_pools)) {
    iVar3 = *(int *)(pools + lVar2 * 4);
    lVar2 = strtol(pcVar1 + 1,(char **)0x0,10);
    if (-1 < lVar2) {
      *(long *)(iVar3 + 0x38) = lVar2;
      adjust_quota_gcd();
      message(param_1,0x7a,lVar2,*(undefined4 *)(iVar3 + 0xa4));
      return;
    }
    message(param_1,0x79,lVar2,*(undefined4 *)(iVar3 + 0xa4));
    return;
  }
  message(param_1,0x1a,lVar2,0);
  return;
}

