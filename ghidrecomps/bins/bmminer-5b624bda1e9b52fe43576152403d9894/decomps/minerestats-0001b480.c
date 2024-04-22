
/* WARNING: Variable defined which should be unmapped: id */
/* WARNING: Unknown calling convention */

void minerestats(io_data *io_data,long c,char *param,_Bool isjson,char group)

{
  int *piVar1;
  _Bool _Var2;
  cgpu_info *pcVar3;
  cgpu_info *cgpu;
  int i;
  api_data *extra_00;
  device_drv *pdVar5;
  int id_00;
  api_data *extra;
  cgpu_info *in_stack_ffffffc0;
  char id [20];
  api_data *paVar4;
  
  extra_00 = (api_data *)(uint)isjson;
  message(io_data,0x46,0,(char *)0x0,isjson);
  paVar4 = extra_00;
  if (extra_00 != (api_data *)0x0) {
    _Var2 = io_add(io_data,DAT_0001b518);
    paVar4 = (api_data *)(uint)_Var2;
  }
  piVar1 = DAT_0001b51c;
  if (0 < *DAT_0001b51c) {
    id_00 = 0;
    i = id_00;
    do {
      pcVar3 = get_devices(id_00);
      if ((pcVar3 != (cgpu_info *)0x0) && (pdVar5 = pcVar3->drv, pdVar5 != (device_drv *)0x0)) {
        extra = (api_data *)pdVar5->get_api_stats;
        if (extra != (api_data *)0x0) {
          extra = (api_data *)(*(code *)extra)();
          pdVar5 = pcVar3->drv;
        }
        sprintf(id,DAT_0001b514,pdVar5->name,pcVar3->device_id);
        i = itemstats(io_data,i,id,&pcVar3->cgminer_stats,(cgminer_pool_stats *)extra,extra_00,
                      in_stack_ffffffc0,(_Bool)id[0]);
      }
      id_00 = id_00 + 1;
    } while (id_00 < *piVar1);
  }
  if (paVar4 != (api_data *)0x0) {
    io_data->close = true;
  }
  return;
}

