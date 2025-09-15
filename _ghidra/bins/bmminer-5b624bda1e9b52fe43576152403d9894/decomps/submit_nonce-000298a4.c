
/* WARNING: Unknown calling convention */

_Bool submit_nonce(thr_info *thr,work *work,uint nonce)

{
  _Bool _Var1;
  
  _Var1 = new_nonce(thr,nonce);
  if (_Var1) {
    *(uint *)(work->data + 0x4c) = nonce;
    regen_hash(work);
    if (*(int *)(work->hash + 0x1c) == 0) {
      submit_tested_work(thr,work);
      if ((opt_benchfile != (char *)0x0) && (opt_benchfile_display != false)) {
        benchfile_dspwork(work,nonce);
        return true;
      }
      return true;
    }
  }
  inc_hw_errors(thr);
  return false;
}

