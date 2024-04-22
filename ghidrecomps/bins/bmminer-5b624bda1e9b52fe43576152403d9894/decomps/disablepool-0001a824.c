
/* WARNING: Unknown calling convention */

void disablepool(io_data *io_data,long c,char *param,_Bool isjson,char group)

{
  int *piVar1;
  long paramid;
  pool *ppVar2;
  pool *ppVar3;
  pool *pool;
  int id;
  
  piVar1 = DAT_0001a8e4;
  if (*DAT_0001a8e4 == 0) {
    message(io_data,8,0,(char *)0x0,isjson);
    return;
  }
  if ((param == (char *)0x0) || (*param == '\0')) {
    message(io_data,0x19,0,(char *)0x0,isjson);
    return;
  }
  paramid = strtol(param,(char **)0x0,10);
  if ((paramid < 0) || (*piVar1 <= paramid)) {
    message(io_data,0x1a,paramid,(char *)0x0,isjson);
    return;
  }
  ppVar3 = *(pool **)(*DAT_0001a8e8 + paramid * 4);
  if (ppVar3->enabled == POOL_DISABLED) {
    message(io_data,0x32,paramid,(char *)0x0,isjson);
    return;
  }
  if (1 < *DAT_0001a8ec) {
    ppVar3->enabled = POOL_DISABLED;
    ppVar2 = current_pool();
    if (ppVar3 == ppVar2) {
      switch_pools((pool *)0x0);
    }
    message(io_data,0x30,paramid,(char *)0x0,isjson);
    return;
  }
  message(io_data,0x33,paramid,(char *)0x0,isjson);
  return;
}

