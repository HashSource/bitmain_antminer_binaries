
_Bool submit_tested_work(thr_info *thr,work *work)

{
  _Bool _Var1;
  work *work_00;
  work *work_local;
  thr_info *thr_local;
  char tmp42 [2048];
  work *work_out;
  
  update_work_stats(thr,work);
  _Var1 = fulltest(work->hash,work->target);
  if (_Var1) {
    work_00 = copy_work_noffset(work,0);
    submit_work_async(work_00);
    _Var1 = true;
  }
  else {
    if (((use_syslog != false) || (opt_log_output != false)) || (5 < opt_log_level)) {
      snprintf(tmp42,0x800,"%s %s %d: Share above target","submit_tested_work",thr->cgpu->drv->name,
               thr->cgpu->device_id);
      _applog(6,tmp42,false);
    }
    _Var1 = false;
  }
  return _Var1;
}

