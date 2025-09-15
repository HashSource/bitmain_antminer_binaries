
_Bool new_nonce(thr_info *thr,uint nonce)

{
  _Bool _Var1;
  cgpu_info *pcVar2;
  uint nonce_local;
  thr_info *thr_local;
  char tmp42 [2048];
  cgpu_info *cgpu;
  
  pcVar2 = thr->cgpu;
  if (pcVar2->last_nonce == nonce) {
    if (((use_syslog) || (opt_log_output)) || (5 < opt_log_level)) {
      snprintf(tmp42,0x800,"%s %d duplicate share detected as HW error",pcVar2->drv->name,
               pcVar2->device_id);
      _applog(6,tmp42,false);
    }
    _Var1 = false;
  }
  else {
    pcVar2->last_nonce = nonce;
    _Var1 = true;
  }
  return _Var1;
}

