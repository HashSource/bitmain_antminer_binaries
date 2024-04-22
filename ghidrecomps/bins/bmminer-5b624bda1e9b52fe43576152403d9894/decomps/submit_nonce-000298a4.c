
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
      if ((*(int *)(DAT_000298f4 + 0x448) != 0) && (*(char *)(DAT_000298f8 + 0xa60) != '\0')) {
        benchfile_dspwork(work,nonce);
        return true;
      }
      return true;
    }
  }
  inc_hw_errors(thr);
  return false;
}

