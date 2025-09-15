
/* WARNING: Unknown calling convention */

void notifystatus(io_data *io_data,int device,cgpu_info *cgpu,_Bool isjson,char group)

{
  api_data *paVar1;
  undefined1 precom;
  int iVar2;
  char *data;
  int local_1c;
  
  if (cgpu->device_last_not_well == 0) {
    data = "None";
  }
  else if (cgpu->device_not_well_reason < REASON_DEV_THROTTLE) {
    data = *(char **)(CSWTCH_404 + cgpu->device_not_well_reason * 4);
  }
  else {
    data = "Unknown reason - code bug";
  }
  local_1c = device;
  paVar1 = api_add_int((api_data *)0x0,"NOTIFY",&local_1c,false);
  paVar1 = api_add_string(paVar1,"Name",cgpu->drv->name,false);
  paVar1 = api_add_int(paVar1,"ID",&cgpu->device_id,false);
  paVar1 = api_add_time(paVar1,"Last Well",&cgpu->device_last_well,false);
  paVar1 = api_add_time(paVar1,"Last Not Well",&cgpu->device_last_not_well,false);
  paVar1 = api_add_string(paVar1,"Reason Not Well",data,false);
  paVar1 = api_add_int(paVar1,"*Thread Fail Init",&cgpu->thread_fail_init_count,false);
  paVar1 = api_add_int(paVar1,"*Thread Zero Hash",&cgpu->thread_zero_hash_count,false);
  paVar1 = api_add_int(paVar1,"*Thread Fail Queue",&cgpu->thread_fail_queue_count,false);
  paVar1 = api_add_int(paVar1,"*Dev Sick Idle 60s",&cgpu->dev_sick_idle_60_count,false);
  paVar1 = api_add_int(paVar1,"*Dev Dead Idle 600s",&cgpu->dev_dead_idle_600_count,false);
  paVar1 = api_add_int(paVar1,"*Dev Nostart",&cgpu->dev_nostart_count,false);
  paVar1 = api_add_int(paVar1,"*Dev Over Heat",&cgpu->dev_over_heat_count,false);
  paVar1 = api_add_int(paVar1,"*Dev Thermal Cutoff",&cgpu->dev_thermal_cutoff_count,false);
  paVar1 = api_add_int(paVar1,"*Dev Comms Error",&cgpu->dev_comms_error_count,false);
  paVar1 = api_add_int(paVar1,"*Dev Throttle",&cgpu->dev_throttle_count,false);
  precom = isjson;
  if (isjson) {
    iVar2 = local_1c;
    if (local_1c < 1) {
      iVar2 = 0;
    }
    precom = (undefined1)iVar2;
    if (0 < local_1c) {
      precom = true;
    }
  }
  print_data(io_data,paVar1,isjson,(_Bool)precom);
  return;
}

