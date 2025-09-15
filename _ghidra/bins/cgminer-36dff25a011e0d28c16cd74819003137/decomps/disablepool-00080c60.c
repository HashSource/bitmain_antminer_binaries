
void disablepool(io_data *io_data,long c,char *param,_Bool isjson,char group)

{
  int paramid;
  pool *ppVar1;
  pool *ppVar2;
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
      ppVar2 = pools[paramid];
      if (ppVar2->enabled == POOL_DISABLED) {
        message(io_data,0x32,paramid,(char *)0x0,isjson);
      }
      else if (enabled_pools < 2) {
        message(io_data,0x33,paramid,(char *)0x0,isjson);
      }
      else {
        ppVar2->enabled = POOL_DISABLED;
        ppVar1 = current_pool();
        if (ppVar2 == ppVar1) {
          switch_pools((pool *)0x0);
        }
        message(io_data,0x30,paramid,(char *)0x0,isjson);
      }
    }
  }
  return;
}

