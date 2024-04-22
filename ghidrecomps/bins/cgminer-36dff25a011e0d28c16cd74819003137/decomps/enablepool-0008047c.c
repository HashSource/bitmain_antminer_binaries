
void enablepool(io_data *io_data,long c,char *param,_Bool isjson,char group)

{
  int paramid;
  pool *ppVar1;
  pool *selected;
  int iVar2;
  _Bool isjson_local;
  char *param_local;
  long c_local;
  io_data *io_data_local;
  pool *pool;
  int id;
  
  if (total_pools == 0) {
    message(io_data,8,0,(char *)0x0,isjson);
  }
  else if ((param == (char *)0x0) || (*param == '\0')) {
    message(io_data,0x19,0,(char *)0x0,isjson);
  }
  else {
    paramid = atoi(param);
    if ((paramid < 0) || (total_pools <= paramid)) {
      message(io_data,0x1a,paramid,(char *)0x0,isjson);
    }
    else {
      selected = pools[paramid];
      if (selected->enabled == POOL_ENABLED) {
        message(io_data,0x31,paramid,(char *)0x0,isjson);
      }
      else {
        selected->enabled = POOL_ENABLED;
        iVar2 = selected->prio;
        ppVar1 = current_pool();
        if (iVar2 < ppVar1->prio) {
          switch_pools(selected);
        }
        message(io_data,0x2f,paramid,(char *)0x0,isjson);
      }
    }
  }
  return;
}

