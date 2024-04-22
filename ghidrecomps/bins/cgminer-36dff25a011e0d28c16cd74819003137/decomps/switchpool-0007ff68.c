
void switchpool(io_data *io_data,long c,char *param,_Bool isjson,char group)

{
  int paramid;
  pool *selected;
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
    _cg_rlock(&control_lock,"api-btm.c","switchpool",0xb50);
    if ((paramid < 0) || (total_pools <= paramid)) {
      _cg_runlock(&control_lock,"api-btm.c","switchpool",0xb53);
      message(io_data,0x1a,paramid,(char *)0x0,isjson);
    }
    else {
      selected = pools[paramid];
      selected->enabled = POOL_ENABLED;
      _cg_runlock(&control_lock,"api-btm.c","switchpool",0xb5a);
      switch_pools(selected);
      message(io_data,0x1b,paramid,(char *)0x0,isjson);
    }
  }
  return;
}

