
/* WARNING: Variable defined which should be unmapped: id */
/* WARNING: Unknown calling convention */

void minerstats(io_data *io_data,long c,char *param,_Bool isjson,char group)

{
  int *piVar1;
  _Bool _Var2;
  api_data *paVar3;
  cgpu_info *pcVar4;
  cgpu_info *cgpu;
  int i;
  api_data *extra_00;
  device_drv *pdVar6;
  int id_00;
  api_data *extra;
  cgpu_info *in_stack_ffffffc0;
  char id [20];
  api_data *paVar5;
  
  extra_00 = (api_data *)(uint)isjson;
  message(io_data,0x46,0,(char *)0x0,isjson);
  paVar5 = extra_00;
  if (extra_00 != (api_data *)0x0) {
    _Var2 = io_add(io_data,DAT_0001b60c);
    paVar5 = (api_data *)(uint)_Var2;
  }
  paVar3 = api_add_string((api_data *)0x0,DAT_0001b5e8,DAT_0001b5ec,false);
  paVar3 = api_add_string(paVar3,DAT_0001b5f0,DAT_0001b5f4,false);
  piVar1 = DAT_0001b610;
  paVar3 = api_add_string(paVar3,DAT_0001b5f8,DAT_0001b5fc,false);
  paVar3 = api_add_string(paVar3,DAT_0001b600,DAT_0001b604,false);
  print_data(io_data,paVar3,isjson,false);
  if (0 < *piVar1) {
    id_00 = 0;
    i = id_00;
    do {
      pcVar4 = get_devices(id_00);
      if ((pcVar4 != (cgpu_info *)0x0) && (pdVar6 = pcVar4->drv, pdVar6 != (device_drv *)0x0)) {
        extra = (api_data *)pdVar6->get_api_stats;
        if (extra != (api_data *)0x0) {
          extra = (api_data *)(*(code *)extra)();
          pdVar6 = pcVar4->drv;
        }
        sprintf(id,DAT_0001b608,pdVar6->name,pcVar4->device_id);
        i = itemstats(io_data,i,id,&pcVar4->cgminer_stats,(cgminer_pool_stats *)extra,extra_00,
                      in_stack_ffffffc0,(_Bool)id[0]);
      }
      id_00 = id_00 + 1;
    } while (id_00 < *piVar1);
  }
  if (paVar5 != (api_data *)0x0) {
    io_data->close = true;
  }
  return;
}

