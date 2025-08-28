
void mt_disable(thr_info *mythr,int thr_id,device_drv *drv)

{
  cgpu_info *pcVar1;
  device_drv *drv_local;
  int thr_id_local;
  thr_info *mythr_local;
  char tmp42 [2048];
  
  if (((use_syslog) || (opt_log_output)) || (3 < opt_log_level)) {
    snprintf(tmp42,0x800,"Thread %d being disabled",thr_id);
    _applog(4,tmp42,false);
  }
  pcVar1 = mythr->cgpu;
  *(undefined4 *)&pcVar1->rolling = 0;
  *(undefined4 *)((int)&pcVar1->rolling + 4) = 0;
  if ((opt_debug != false) &&
     (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
    builtin_strncpy(tmp42,"Waiting on sem in miner thre",0x1c);
    tmp42[0x1c] = 'a';
    tmp42[0x1d] = 'd';
    tmp42[0x1e] = '\0';
    _applog(7,tmp42,false);
  }
  _cgsem_wait(&mythr->sem,"cgminer.c","mt_disable",0x233f);
  if (((use_syslog != false) || (opt_log_output != false)) || (3 < opt_log_level)) {
    snprintf(tmp42,0x800,"Thread %d being re-enabled",thr_id);
    _applog(4,tmp42,false);
  }
  (*drv->thread_enable)(mythr);
  return;
}

