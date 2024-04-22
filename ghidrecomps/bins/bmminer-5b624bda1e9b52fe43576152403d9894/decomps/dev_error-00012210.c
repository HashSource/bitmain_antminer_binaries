
/* WARNING: Unknown calling convention */

void dev_error(cgpu_info *dev,dev_reason reason)

{
  time_t tVar1;
  
  tVar1 = time((time_t *)0x0);
  dev->device_not_well_reason = reason;
  dev->device_last_not_well = tVar1;
  switch(reason) {
  case REASON_THREAD_FAIL_INIT:
    dev->thread_fail_init_count = dev->thread_fail_init_count + 1;
    return;
  case REASON_THREAD_ZERO_HASH:
    dev->thread_zero_hash_count = dev->thread_zero_hash_count + 1;
    return;
  case REASON_THREAD_FAIL_QUEUE:
    dev->thread_fail_queue_count = dev->thread_fail_queue_count + 1;
    return;
  case REASON_DEV_SICK_IDLE_60:
    dev->dev_sick_idle_60_count = dev->dev_sick_idle_60_count + 1;
    return;
  case REASON_DEV_DEAD_IDLE_600:
    dev->dev_dead_idle_600_count = dev->dev_dead_idle_600_count + 1;
    return;
  case REASON_DEV_NOSTART:
    dev->dev_nostart_count = dev->dev_nostart_count + 1;
    return;
  case REASON_DEV_OVER_HEAT:
    dev->dev_over_heat_count = dev->dev_over_heat_count + 1;
    return;
  case REASON_DEV_THERMAL_CUTOFF:
    dev->dev_thermal_cutoff_count = dev->dev_thermal_cutoff_count + 1;
    return;
  case REASON_DEV_COMMS_ERROR:
    dev->dev_comms_error_count = dev->dev_comms_error_count + 1;
    return;
  case REASON_DEV_THROTTLE:
    dev->dev_throttle_count = dev->dev_throttle_count + 1;
  }
  return;
}

