
/* WARNING: Unknown calling convention */

void poolquota(io_data *io_data,long c,char *param,_Bool isjson,char group)

{
  char *pcVar1;
  long lVar2;
  pool *ppVar3;
  int quota;
  
  if (total_pools == 0) {
    message(io_data,8,0,(char *)0x0,isjson);
    return;
  }
  if ((param == (char *)0x0) || (*param == '\0')) {
    message(io_data,0x19,0,(char *)0x0,isjson);
    return;
  }
  pcVar1 = strchr(param,0x2c);
  if (pcVar1 == (char *)0x0) {
    message(io_data,0x56,0,param,isjson);
    return;
  }
  *pcVar1 = '\0';
  lVar2 = strtol(param,(char **)0x0,10);
  if ((-1 < lVar2) && (lVar2 < total_pools)) {
    ppVar3 = pools[lVar2];
    lVar2 = strtol(pcVar1 + 1,(char **)0x0,10);
    if (-1 < lVar2) {
      ppVar3->quota = lVar2;
      adjust_quota_gcd();
      message(io_data,0x7a,lVar2,ppVar3->rpc_url,isjson);
      return;
    }
    message(io_data,0x79,lVar2,ppVar3->rpc_url,isjson);
    return;
  }
  message(io_data,0x1a,lVar2,(char *)0x0,isjson);
  return;
}

