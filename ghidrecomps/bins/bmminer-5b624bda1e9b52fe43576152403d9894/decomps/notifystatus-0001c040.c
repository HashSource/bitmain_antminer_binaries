
/* WARNING: Unknown calling convention */

void notifystatus(io_data *io_data,int device,cgpu_info *cgpu,_Bool isjson,char group)

{
  api_data *paVar1;
  undefined precom;
  int iVar2;
  char *reason;
  int local_1c;
  
  reason = DAT_0001c14c;
  if ((cgpu->device_last_not_well != 0) &&
     (reason = DAT_0001c148, cgpu->device_not_well_reason < REASON_DEV_THROTTLE)) {
    reason = *(char **)(DAT_0001c190 + cgpu->device_not_well_reason * 4 + 0x70);
  }
  local_1c = device;
  paVar1 = api_add_int((api_data *)0x0,DAT_0001c150,&local_1c,false);
  paVar1 = api_add_string(paVar1,DAT_0001c154,cgpu->drv->name,false);
  paVar1 = api_add_int(paVar1,DAT_0001c158,&cgpu->device_id,false);
  paVar1 = api_add_time(paVar1,DAT_0001c15c,&cgpu->device_last_well,false);
  paVar1 = api_add_time(paVar1,DAT_0001c160,&cgpu->device_last_not_well,false);
  paVar1 = api_add_string(paVar1,DAT_0001c164,reason,false);
  paVar1 = api_add_int(paVar1,DAT_0001c168,&cgpu->thread_fail_init_count,false);
  paVar1 = api_add_int(paVar1,DAT_0001c16c,&cgpu->thread_zero_hash_count,false);
  paVar1 = api_add_int(paVar1,DAT_0001c170,&cgpu->thread_fail_queue_count,false);
  paVar1 = api_add_int(paVar1,DAT_0001c174,&cgpu->dev_sick_idle_60_count,false);
  paVar1 = api_add_int(paVar1,DAT_0001c178,&cgpu->dev_dead_idle_600_count,false);
  paVar1 = api_add_int(paVar1,DAT_0001c17c,&cgpu->dev_nostart_count,false);
  paVar1 = api_add_int(paVar1,DAT_0001c180,&cgpu->dev_over_heat_count,false);
  paVar1 = api_add_int(paVar1,DAT_0001c184,&cgpu->dev_thermal_cutoff_count,false);
  paVar1 = api_add_int(paVar1,DAT_0001c188,&cgpu->dev_comms_error_count,false);
  paVar1 = api_add_int(paVar1,DAT_0001c18c,&cgpu->dev_throttle_count,false);
  precom = isjson;
  if (isjson) {
    iVar2 = local_1c;
    if (local_1c < 1) {
      iVar2 = 0;
    }
    precom = (undefined)iVar2;
    if (0 < local_1c) {
      precom = true;
    }
  }
  print_data(io_data,paVar1,isjson,(_Bool)precom);
  return;
}

