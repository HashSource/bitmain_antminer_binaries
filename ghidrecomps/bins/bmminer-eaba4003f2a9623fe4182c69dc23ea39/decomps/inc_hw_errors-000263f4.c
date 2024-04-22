
void inc_hw_errors(thr_info *thr)

{
  thr_info *thr_local;
  char tmp42 [2048];
  
  if (((use_syslog) || (opt_log_output)) || (5 < opt_log_level)) {
    snprintf(tmp42,0x800,"%s %d: invalid nonce - HW error",thr->cgpu->drv->name,thr->cgpu->device_id
            );
    _applog(6,tmp42,false);
  }
  _mutex_lock(&stats_lock,"cgminer.c","inc_hw_errors",0x21c1);
  hw_errors = hw_errors + 1;
  thr->cgpu->hw_errors = thr->cgpu->hw_errors + 1;
  _mutex_unlock(&stats_lock,"cgminer.c","inc_hw_errors",0x21c4);
  (*thr->cgpu->drv->hw_error)(thr);
  return;
}

