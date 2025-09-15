
/* WARNING: Unknown calling convention */

void enablepool(io_data *io_data,long c,char *param,_Bool isjson,char group)

{
  long paramid;
  pool *ppVar1;
  pool *selected;
  int id;
  int iVar2;
  
  if (total_pools == 0) {
    message(io_data,8,0,(char *)0x0,isjson);
    return;
  }
  if ((param != (char *)0x0) && (*param != '\0')) {
    paramid = strtol(param,(char **)0x0,10);
    if ((-1 < paramid) && (paramid < total_pools)) {
      selected = pools[paramid];
      if (selected->enabled != POOL_ENABLED) {
        iVar2 = selected->prio;
        selected->enabled = POOL_ENABLED;
        ppVar1 = current_pool();
        if (iVar2 < ppVar1->prio) {
          switch_pools(selected);
        }
        message(io_data,0x2f,paramid,(char *)0x0,isjson);
        return;
      }
      message(io_data,0x31,paramid,(char *)0x0,isjson);
      return;
    }
    message(io_data,0x1a,paramid,(char *)0x0,isjson);
    return;
  }
  message(io_data,0x19,0,(char *)0x0,isjson);
  return;
}

