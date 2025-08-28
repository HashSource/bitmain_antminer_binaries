
/* WARNING: Unknown calling convention */

_Bool submit_nonce_1(thr_info *thr,work *work,uint nonce,int *nofull)

{
  _Bool _Var1;
  char tmp42 [2048];
  
  if (nofull != (int *)0x0) {
    *nofull = 0;
  }
  *(uint *)(work->data + 0x4c) = nonce;
  regen_hash(work);
  if (*(int *)(work->hash + 0x1c) == 0) {
    update_work_stats(thr,work);
    _Var1 = fulltest(work->hash,work->target);
    if (_Var1) {
      _Var1 = true;
    }
    else {
      if (nofull != (int *)0x0) {
        *nofull = 1;
      }
      if (((use_syslog != false) || (opt_log_output != false)) || (_Var1 = false, 5 < opt_log_level)
         ) {
        builtin_strncpy(tmp42,"Share above targ",0x10);
        tmp42[0x10] = 'e';
        tmp42[0x11] = 't';
        tmp42[0x12] = '\0';
        _applog(6,tmp42,false);
        _Var1 = false;
      }
    }
  }
  else {
    inc_hw_errors(thr);
    _Var1 = false;
  }
  return _Var1;
}

