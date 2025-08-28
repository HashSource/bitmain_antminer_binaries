
/* WARNING: Variable defined which should be unmapped: id */
/* WARNING: Unknown calling convention */

void minerestats(io_data *io_data,long c,char *param,_Bool isjson,char group)

{
  _Bool _Var1;
  cgpu_info *pcVar2;
  int i;
  api_data *extra;
  device_drv *pdVar4;
  int id_00;
  cgminer_pool_stats *pool_stats;
  cgpu_info *in_stack_ffffffc0;
  char id [20];
  api_data *paVar3;
  
  extra = (api_data *)(uint)isjson;
  message(io_data,0x46,0,(char *)0x0,isjson);
  paVar3 = extra;
  if (extra != (api_data *)0x0) {
    _Var1 = io_add(io_data,",\"STATS\":[");
    paVar3 = (api_data *)(uint)_Var1;
  }
  if (0 < total_devices) {
    id_00 = 0;
    i = id_00;
    do {
      pcVar2 = get_devices(id_00);
      if ((pcVar2 != (cgpu_info *)0x0) && (pdVar4 = pcVar2->drv, pdVar4 != (device_drv *)0x0)) {
        pool_stats = (cgminer_pool_stats *)pdVar4->get_api_stats;
        if (pool_stats != (cgminer_pool_stats *)0x0) {
          pool_stats = (cgminer_pool_stats *)(*(code *)pool_stats)();
          pdVar4 = pcVar2->drv;
        }
        sprintf(id,"%s%d",pdVar4->name,pcVar2->device_id);
        i = itemstats(io_data,i,id,&pcVar2->cgminer_stats,pool_stats,extra,in_stack_ffffffc0,
                      (_Bool)id[0]);
      }
      id_00 = id_00 + 1;
    } while (id_00 < total_devices);
  }
  if (paVar3 != (api_data *)0x0) {
    io_data->close = true;
  }
  return;
}

