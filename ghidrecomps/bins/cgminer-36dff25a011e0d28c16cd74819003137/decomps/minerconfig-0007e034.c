
void minerconfig(io_data *io_data,long c,char *param,_Bool isjson,char group)

{
  uint uVar1;
  _Bool isjson_local;
  char *param_local;
  long c_local;
  io_data *io_data_local;
  int pgacount;
  int asccount;
  _Bool io_open;
  api_data *root;
  
  root = (api_data *)0x0;
  asccount = 0;
  pgacount = 0;
  asccount = numascs();
  message(io_data,0x21,0,(char *)0x0,isjson);
  if (isjson) {
    uVar1 = 0xdbc8;
  }
  else {
    uVar1 = 0xdbd4;
  }
  io_open = io_add(io_data,(char *)(uVar1 | 0xa0000));
  root = api_add_int(root,"ASC Count",&asccount,false);
  root = api_add_int(root,"PGA Count",&pgacount,false);
  root = api_add_int(root,"Pool Count",&total_pools,false);
  root = api_add_const(root,"Strategy",*(char **)(&strategies + pool_strategy * 4),false);
  root = api_add_int(root,"Log Interval",&opt_log_interval,false);
  root = api_add_const(root,"Device Code",DEVICECODE,false);
  root = api_add_const(root,"OS",OSINFO,false);
  root = api_add_const(root,"Hotplug",NONE,false);
  root = print_data(io_data,root,isjson,false);
  if ((isjson) && (io_open != false)) {
    io_close(io_data);
  }
  return;
}

