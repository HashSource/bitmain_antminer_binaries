
_Bool submit_noffset_nonce(thr_info *thr,work *work_in,uint nonce,int noffset)

{
  _Bool _Var1;
  int noffset_local;
  uint nonce_local;
  work *work_in_local;
  thr_info *thr_local;
  char tmp42 [2048];
  work *work;
  _Bool ret;
  
  work = make_work();
  ret = false;
  _copy_work(work,work_in,noffset);
  _Var1 = test_nonce(work,nonce);
  if (_Var1) {
    update_work_stats(thr,work);
    if ((opt_benchfile != (char *)0x0) && (opt_benchfile_display != false)) {
      benchfile_dspwork(work,nonce);
    }
    ret = true;
    _Var1 = fulltest(work->hash,work->target);
    if (_Var1) {
      submit_work_async(work);
    }
    else {
      _free_work(&work,"cgminer.c","submit_noffset_nonce",0x2325);
      if (((use_syslog != false) || (opt_log_output != false)) || (5 < opt_log_level)) {
        snprintf(tmp42,0x800,"%s %d: Share above target",thr->cgpu->drv->name,thr->cgpu->device_id);
        _applog(6,tmp42,false);
      }
    }
  }
  else {
    _free_work(&work,"cgminer.c","submit_noffset_nonce",0x2315);
    inc_hw_errors(thr);
  }
  return ret;
}

