
/* WARNING: Unknown calling convention */

void removepool(io_data *io_data,long c,char *param,_Bool isjson,char group)

{
  long paramid;
  pool *ppVar1;
  char *param2;
  pool *pool;
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
  if (total_pools < 2) {
    message(io_data,0x42,paramid,(char *)0x0,isjson);
    return;
  }
  pool = pools[paramid];
  ppVar1 = current_pool();
  if (pool == ppVar1) {
    switch_pools((pool *)0x0);
  }
  ppVar1 = current_pool();
  if (pool == ppVar1) {
    message(io_data,0x43,paramid,(char *)0x0,isjson);
    return;
  }
  pool->enabled = POOL_DISABLED;
  param2 = escape_string(pool->rpc_url,isjson);
  if (param2 == pool->rpc_url) {
    remove_pool(pool);
    message(io_data,0x44,paramid,param2,isjson);
    return;
  }
  remove_pool(pool);
  message(io_data,0x44,paramid,param2,isjson);
  (*(code *)(undefined *)0x0)(param2);
  return;
}

