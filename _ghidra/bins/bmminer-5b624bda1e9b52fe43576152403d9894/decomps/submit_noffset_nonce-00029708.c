
/* WARNING: Unknown calling convention */

_Bool submit_noffset_nonce(thr_info *thr,work *work_in,uint nonce,int noffset)

{
  work *pwVar1;
  _Bool _Var2;
  work *work;
  char tmp42 [2048];
  
  work = make_work();
  _copy_work(work,work_in,noffset);
  pwVar1 = work;
  *(uint *)(work->data + 0x4c) = nonce;
  regen_hash(work);
  if (*(int *)(pwVar1->hash + 0x1c) == 0) {
    update_work_stats(thr,work);
    if ((opt_benchfile != (char *)0x0) && (opt_benchfile_display != false)) {
      benchfile_dspwork(work,nonce);
    }
    _Var2 = fulltest(work->hash,work->target);
    if (_Var2) {
      submit_work_async(work);
      _Var2 = true;
    }
    else {
      _free_work(&work,"cgminer.c","submit_noffset_nonce",0x231e);
      if (((use_syslog == false) && (opt_log_output == false)) && (opt_log_level < 6)) {
        _Var2 = true;
      }
      else {
        snprintf(tmp42,0x800,"%s %d: Share above target",thr->cgpu->drv->name,thr->cgpu->device_id);
        _applog(6,tmp42,false);
        _Var2 = true;
      }
    }
  }
  else {
    _free_work(&work,"cgminer.c","submit_noffset_nonce",0x230e);
    inc_hw_errors(thr);
    _Var2 = false;
  }
  return _Var2;
}

