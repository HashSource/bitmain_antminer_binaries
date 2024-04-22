
void notifystatus(io_data *io_data,int device,cgpu_info *cgpu,_Bool isjson,char group)

{
  _Bool precom;
  _Bool isjson_local;
  cgpu_info *cgpu_local;
  int device_local;
  io_data *io_data_local;
  api_data *root;
  char *reason;
  
  root = (api_data *)0x0;
  if (cgpu->device_last_not_well == 0) {
    reason = "None";
  }
  else {
    switch(cgpu->device_not_well_reason) {
    case REASON_THREAD_FAIL_INIT:
      reason = "Thread failed to init";
      break;
    case REASON_THREAD_ZERO_HASH:
      reason = "Thread got zero hashes";
      break;
    case REASON_THREAD_FAIL_QUEUE:
      reason = "Thread failed to queue work";
      break;
    case REASON_DEV_SICK_IDLE_60:
      reason = "Device idle for 60s";
      break;
    case REASON_DEV_DEAD_IDLE_600:
      reason = "Device dead - idle for 600s";
      break;
    case REASON_DEV_NOSTART:
      reason = "Device failed to start";
      break;
    case REASON_DEV_OVER_HEAT:
      reason = "Device over heated";
      break;
    case REASON_DEV_THERMAL_CUTOFF:
      reason = "Device reached thermal cutoff";
      break;
    case REASON_DEV_COMMS_ERROR:
      reason = "Device comms error";
      break;
    default:
      reason = "Unknown reason - code bug";
    }
  }
  device_local = device;
  io_data_local = io_data;
  root = api_add_int((api_data *)0x0,"NOTIFY",&device_local,false);
  root = api_add_string(root,"Name",cgpu->drv->name,false);
  root = api_add_int(root,"ID",&cgpu->device_id,false);
  root = api_add_time(root,"Last Well",&cgpu->device_last_well,false);
  root = api_add_time(root,"Last Not Well",&cgpu->device_last_not_well,false);
  root = api_add_string(root,"Reason Not Well",reason,false);
  root = api_add_int(root,"*Thread Fail Init",&cgpu->thread_fail_init_count,false);
  root = api_add_int(root,"*Thread Zero Hash",&cgpu->thread_zero_hash_count,false);
  root = api_add_int(root,"*Thread Fail Queue",&cgpu->thread_fail_queue_count,false);
  root = api_add_int(root,"*Dev Sick Idle 60s",&cgpu->dev_sick_idle_60_count,false);
  root = api_add_int(root,"*Dev Dead Idle 600s",&cgpu->dev_dead_idle_600_count,false);
  root = api_add_int(root,"*Dev Nostart",&cgpu->dev_nostart_count,false);
  root = api_add_int(root,"*Dev Over Heat",&cgpu->dev_over_heat_count,false);
  root = api_add_int(root,"*Dev Thermal Cutoff",&cgpu->dev_thermal_cutoff_count,false);
  root = api_add_int(root,"*Dev Comms Error",&cgpu->dev_comms_error_count,false);
  root = api_add_int(root,"*Dev Throttle",&cgpu->dev_throttle_count,false);
  if ((isjson) && (0 < device_local)) {
    precom = true;
  }
  else {
    precom = false;
  }
  print_data(io_data_local,root,isjson,precom);
  return;
}

