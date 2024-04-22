
/* WARNING: Unknown calling convention */
/* Local variable id:int[r3:4] conflicts with parameter, skipped. */

void poolquota(io_data *io_data,long c,char *param,_Bool isjson,char group)

{
  int *piVar1;
  char *pcVar2;
  char *comma;
  long lVar3;
  int iVar4;
  pool *pool;
  int quota;
  
  piVar1 = DAT_0001aa70;
  if (*DAT_0001aa70 == 0) {
    message(io_data,8,0,(char *)0x0,isjson);
    return;
  }
  if ((param == (char *)0x0) || (*param == '\0')) {
    message(io_data,0x19,0,(char *)0x0,isjson);
    return;
  }
  pcVar2 = strchr(param,0x2c);
  if (pcVar2 == (char *)0x0) {
    message(io_data,0x56,0,param,isjson);
    return;
  }
  *pcVar2 = '\0';
  lVar3 = strtol(param,(char **)0x0,10);
  if ((-1 < lVar3) && (lVar3 < *piVar1)) {
    iVar4 = *(int *)(*DAT_0001aa74 + lVar3 * 4);
    lVar3 = strtol(pcVar2 + 1,(char **)0x0,10);
    if (-1 < lVar3) {
      *(long *)(iVar4 + 0x38) = lVar3;
      adjust_quota_gcd();
      message(io_data,0x7a,lVar3,*(char **)(iVar4 + 0xa4),isjson);
      return;
    }
    message(io_data,0x79,lVar3,*(char **)(iVar4 + 0xa4),isjson);
    return;
  }
  message(io_data,0x1a,lVar3,(char *)0x0,isjson);
  return;
}

