
/* WARNING: Unknown calling convention */

void minerconfig(io_data *io_data,long c,char *param,_Bool isjson,char group)

{
  _Bool _Var1;
  api_data *paVar2;
  char *buf;
  undefined1 extraout_r3;
  undefined1 uVar3;
  int asccount;
  int pgacount;
  
  asccount = 0;
  pgacount = 0;
  message(io_data,0x21,0,(char *)0x0,isjson);
  buf = "CONFIG,";
  if (isjson) {
    buf = ",\"CONFIG\":[";
  }
  _Var1 = io_add(io_data,buf);
  paVar2 = api_add_int((api_data *)0x0,"ASC Count",&asccount,false);
  paVar2 = api_add_int(paVar2,"PGA Count",&pgacount,false);
  paVar2 = api_add_int(paVar2,"Pool Count",&total_pools,false);
  paVar2 = api_add_const(paVar2,"Strategy",strategies[pool_strategy].s,false);
  paVar2 = api_add_int(paVar2,"Log Interval",&opt_log_interval,false);
  paVar2 = api_add_const(paVar2,"Device Code","",false);
  paVar2 = api_add_const(paVar2,"OS","Linux",false);
  paVar2 = api_add_bool(paVar2,"Failover-Only",&opt_fail_only,false);
  paVar2 = api_add_int(paVar2,"ScanTime",&opt_scantime,false);
  paVar2 = api_add_int(paVar2,"Queue",&opt_queue,false);
  paVar2 = api_add_int(paVar2,"Expiry",&opt_expiry,false);
  paVar2 = api_add_const(paVar2,"Hotplug","None",false);
  print_data(io_data,paVar2,isjson,false);
  uVar3 = extraout_r3;
  if (_Var1 && isjson) {
    uVar3 = true;
  }
  if (_Var1 && isjson) {
    io_data->close = (_Bool)uVar3;
  }
  return;
}

