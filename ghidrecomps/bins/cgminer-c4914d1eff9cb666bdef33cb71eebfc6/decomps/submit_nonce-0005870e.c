
_Bool submit_nonce(thr_info *thr,work *work,uint32_t nonce)

{
  _Bool _Var1;
  uint32_t nonce_local;
  work *work_local;
  thr_info *thr_local;
  
  _Var1 = new_nonce(thr,nonce);
  if ((_Var1) && (_Var1 = test_nonce(work,nonce), _Var1)) {
    submit_tested_work(thr,work);
    if ((opt_benchfile != (char *)0x0) && (opt_benchfile_display != false)) {
      benchfile_dspwork(work,nonce);
    }
    _Var1 = true;
  }
  else {
    inc_hw_errors(thr);
    _Var1 = false;
  }
  return _Var1;
}

