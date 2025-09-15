
/* WARNING: Unknown calling convention */

void disablepool(io_data *io_data,long c,char *param,_Bool isjson,char group)

{
  long paramid;
  pool *ppVar1;
  pool *ppVar2;
  int id;
  
  if (total_pools == 0) {
    message(io_data,8,0,(char *)0x0,isjson);
    return;
  }
  if ((param == (char *)0x0) || (*param == '\0')) {
    message(io_data,0x19,0,(char *)0x0,isjson);
    return;
  }
  paramid = strtol(param,(char **)0x0,10);
  if ((paramid < 0) || (total_pools <= paramid)) {
    message(io_data,0x1a,paramid,(char *)0x0,isjson);
    return;
  }
  ppVar2 = pools[paramid];
  if (ppVar2->enabled == POOL_DISABLED) {
    message(io_data,0x32,paramid,(char *)0x0,isjson);
    return;
  }
  if (1 < enabled_pools) {
    ppVar2->enabled = POOL_DISABLED;
    ppVar1 = current_pool();
    if (ppVar2 == ppVar1) {
      switch_pools((pool *)0x0);
    }
    message(io_data,0x30,paramid,(char *)0x0,isjson);
    return;
  }
  message(io_data,0x33,paramid,(char *)0x0,isjson);
  return;
}

