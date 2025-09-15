
/* WARNING: Unknown calling convention */

void mt_disable(thr_info *mythr,int thr_id,device_drv *drv)

{
  _Bool _Var1;
  char tmp42 [2048];
  
  if (((use_syslog) || (opt_log_output)) || (3 < opt_log_level)) {
    snprintf(tmp42,0x800,"Thread %d being disabled",thr_id);
    _applog(4,tmp42,false);
  }
  _Var1 = opt_debug;
  mythr->cgpu->rolling = 0.0;
  if ((_Var1 != false) &&
     (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
    builtin_strncpy(tmp42,"Waiting on sem in miner thre",0x1c);
    tmp42[0x1c] = 'a';
    tmp42[0x1d] = 'd';
    tmp42[0x1e] = '\0';
    _applog(7,tmp42,false);
  }
  _cgsem_wait(&mythr->sem,"cgminer.c","mt_disable",0x2338);
  if (((use_syslog != false) || (opt_log_output != false)) || (3 < opt_log_level)) {
    snprintf(tmp42,0x800,"Thread %d being re-enabled",thr_id);
    _applog(4,tmp42,false);
  }
  (*drv->thread_enable)(mythr);
  return;
}

