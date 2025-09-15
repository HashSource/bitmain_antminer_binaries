
void inc_hw_errors_with_diff(thr_info *thr,int diff)

{
  int diff_local;
  thr_info *thr_local;
  char tmp42 [2048];
  
  if (((use_syslog) || (opt_log_output)) || (2 < opt_log_level)) {
    snprintf(tmp42,0x800,"%s%d: invalid nonce - HW error",thr->cgpu->drv->name,thr->cgpu->device_id)
    ;
    _applog(3,tmp42,false);
  }
  _mutex_lock(&stats_lock,"cgminer.c","inc_hw_errors_with_diff",0x21ce);
  hw_errors = hw_errors + diff;
  thr->cgpu->hw_errors = thr->cgpu->hw_errors + diff;
  _mutex_unlock(&stats_lock,"cgminer.c","inc_hw_errors_with_diff",0x21d1);
  (*thr->cgpu->drv->hw_error)(thr);
  return;
}

