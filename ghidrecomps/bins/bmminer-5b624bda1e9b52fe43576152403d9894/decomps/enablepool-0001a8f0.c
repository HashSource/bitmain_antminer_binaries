
/* WARNING: Unknown calling convention */

void enablepool(io_data *io_data,long c,char *param,_Bool isjson,char group)

{
  int *piVar1;
  long paramid;
  pool *ppVar2;
  pool *selected;
  pool *pool;
  int id;
  int iVar3;
  
  piVar1 = DAT_0001a99c;
  if (*DAT_0001a99c == 0) {
    message(io_data,8,0,(char *)0x0,isjson);
    return;
  }
  if ((param != (char *)0x0) && (*param != '\0')) {
    paramid = strtol(param,(char **)0x0,10);
    if ((-1 < paramid) && (paramid < *piVar1)) {
      selected = *(pool **)(*DAT_0001a9a0 + paramid * 4);
      if (selected->enabled != POOL_ENABLED) {
        iVar3 = selected->prio;
        selected->enabled = POOL_ENABLED;
        ppVar2 = current_pool();
        if (iVar3 < ppVar2->prio) {
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

