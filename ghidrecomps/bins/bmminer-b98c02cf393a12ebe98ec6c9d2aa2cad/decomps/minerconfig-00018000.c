
void minerconfig(int param_1,undefined4 param_2,undefined4 param_3,uint param_4)

{
  uint uVar1;
  undefined4 uVar2;
  char *pcVar3;
  undefined uVar4;
  bool bVar5;
  undefined4 local_20;
  undefined4 local_1c [2];
  
  local_20 = 0;
  local_1c[0] = 0;
  message(param_1,0x21,0,0,param_4);
  pcVar3 = ",\"CONFIG\":[";
  if (param_4 == 0) {
    pcVar3 = "CONFIG,";
  }
  uVar1 = io_add(param_1,pcVar3);
  uVar2 = api_add_data_full(0,"ASC Count",6,&local_20,0);
  uVar2 = api_add_data_full(uVar2,"PGA Count",6,local_1c,0);
  uVar2 = api_add_data_full(uVar2,"Pool Count",6,&total_pools,0);
  uVar2 = api_add_data_full(uVar2,"Strategy",2,*(undefined4 *)(strategies + pool_strategy * 4),0);
  uVar2 = api_add_data_full(uVar2,"Log Interval",6,&opt_log_interval,0);
  uVar2 = api_add_data_full(uVar2,"Device Code",2,&DAT_000609ec,0);
  uVar2 = api_add_data_full(uVar2,&DAT_00058224,2,"Linux",0);
  uVar2 = api_add_data_full(uVar2,"Failover-Only",0xe,&opt_fail_only,0);
  uVar2 = api_add_data_full(uVar2,"ScanTime",6,&opt_scantime,0);
  uVar2 = api_add_data_full(uVar2,"Queue",6,&opt_queue,0);
  uVar2 = api_add_data_full(uVar2,"Expiry",6,&opt_expiry,0);
  uVar2 = api_add_data_full(uVar2,"Hotplug",2,&DAT_00058254,0);
  uVar4 = 0;
  print_data(param_1,uVar2,param_4);
  bVar5 = (param_4 & uVar1) != 0;
  if (bVar5) {
    uVar4 = 1;
  }
  if (bVar5) {
    *(undefined *)(param_1 + 0xd) = uVar4;
  }
  return;
}

