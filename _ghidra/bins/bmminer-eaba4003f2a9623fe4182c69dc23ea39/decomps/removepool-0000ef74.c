
void removepool(io_data *io_data,long c,char *param,_Bool isjson,char group)

{
  int paramid;
  pool *ppVar1;
  char *param2;
  char *pcVar2;
  pool *pool_00;
  _Bool isjson_local;
  char *param_local;
  long c_local;
  io_data *io_data_local;
  char *rpc_url;
  pool *pool;
  int id;
  _Bool dofree;
  
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
    else if (total_pools < 2) {
      message(io_data,0x42,paramid,(char *)0x0,isjson);
    }
    else {
      pool_00 = pools[paramid];
      ppVar1 = current_pool();
      if (ppVar1 == pool_00) {
        switch_pools((pool *)0x0);
      }
      ppVar1 = current_pool();
      if (ppVar1 == pool_00) {
        message(io_data,0x43,paramid,(char *)0x0,isjson);
      }
      else {
        pool_00->enabled = POOL_DISABLED;
        param2 = escape_string(pool_00->rpc_url,isjson);
        pcVar2 = pool_00->rpc_url;
        remove_pool(pool_00);
        message(io_data,0x44,paramid,param2,isjson);
        if (pcVar2 != param2) {
          free(param2);
        }
      }
    }
  }
  return;
}

