
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
      if (((*DAT_000221b0 != '\0') || (*DAT_000221b4 != '\0')) || (_Var1 = false, 5 < *DAT_000221b8)
         ) {
        tmp42._0_4_ = *DAT_000221bc;
        tmp42._4_4_ = DAT_000221bc[1];
        tmp42._8_4_ = DAT_000221bc[2];
        tmp42._12_4_ = DAT_000221bc[3];
        tmp42._16_2_ = (undefined2)DAT_000221bc[4];
        tmp42[18] = (char)((uint)DAT_000221bc[4] >> 0x10);
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

