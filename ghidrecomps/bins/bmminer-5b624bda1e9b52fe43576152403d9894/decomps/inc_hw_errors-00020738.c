
/* WARNING: Unknown calling convention */

void inc_hw_errors(thr_info *thr)

{
  int iVar1;
  char *func;
  char *func_00;
  int line;
  int line_00;
  char tmp42 [2048];
  
  if (((use_syslog) || (opt_log_output)) || (5 < opt_log_level)) {
    snprintf(tmp42,0x800,"%s %d: invalid nonce - HW error",thr->cgpu->drv->name,thr->cgpu->device_id
            );
    _applog(6,tmp42,false);
  }
  iVar1 = pthread_mutex_lock((pthread_mutex_t *)&stats_lock);
  if (iVar1 != 0) {
    _mutex_lock((pthread_mutex_t *)"inc_hw_errors",(char *)0x21ba,func,line);
  }
  hw_errors = hw_errors + 1;
  thr->cgpu->hw_errors = thr->cgpu->hw_errors + 1;
  iVar1 = pthread_mutex_unlock((pthread_mutex_t *)&stats_lock);
  if (iVar1 != 0) {
    _mutex_unlock_noyield((pthread_mutex_t *)"inc_hw_errors",(char *)0x21bd,func_00,line_00);
  }
  (*selective_yield)();
  (*thr->cgpu->drv->hw_error)(thr);
  return;
}

