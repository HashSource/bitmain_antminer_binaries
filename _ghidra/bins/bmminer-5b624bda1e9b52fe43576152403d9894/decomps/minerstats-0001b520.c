
/* WARNING: Variable defined which should be unmapped: id */
/* WARNING: Unknown calling convention */

void minerstats(io_data *io_data,long c,char *param,_Bool isjson,char group)

{
  _Bool _Var1;
  api_data *paVar2;
  cgpu_info *pcVar3;
  int i;
  api_data *extra;
  device_drv *pdVar5;
  int id_00;
  cgminer_pool_stats *pool_stats;
  cgpu_info *in_stack_ffffffc0;
  char id [20];
  api_data *paVar4;
  
  extra = (api_data *)(uint)isjson;
  message(io_data,0x46,0,(char *)0x0,isjson);
  paVar4 = extra;
  if (extra != (api_data *)0x0) {
    _Var1 = io_add(io_data,",\"STATS\":[");
    paVar4 = (api_data *)(uint)_Var1;
  }
  paVar2 = api_add_string((api_data *)0x0,"BMMiner","2.0.0",false);
  paVar2 = api_add_string(paVar2,"Miner",g_miner_version,false);
  paVar2 = api_add_string(paVar2,"CompileTime",g_miner_compiletime,false);
  paVar2 = api_add_string(paVar2,"Type",g_miner_type,false);
  print_data(io_data,paVar2,isjson,false);
  if (0 < total_devices) {
    id_00 = 0;
    i = id_00;
    do {
      pcVar3 = get_devices(id_00);
      if ((pcVar3 != (cgpu_info *)0x0) && (pdVar5 = pcVar3->drv, pdVar5 != (device_drv *)0x0)) {
        pool_stats = (cgminer_pool_stats *)pdVar5->get_api_stats;
        if (pool_stats != (cgminer_pool_stats *)0x0) {
          pool_stats = (cgminer_pool_stats *)(*(code *)pool_stats)();
          pdVar5 = pcVar3->drv;
        }
        sprintf(id,"%s%d",pdVar5->name,pcVar3->device_id);
        i = itemstats(io_data,i,id,&pcVar3->cgminer_stats,pool_stats,extra,in_stack_ffffffc0,
                      (_Bool)id[0]);
      }
      id_00 = id_00 + 1;
    } while (id_00 < total_devices);
  }
  if (paVar4 != (api_data *)0x0) {
    io_data->close = true;
  }
  return;
}

