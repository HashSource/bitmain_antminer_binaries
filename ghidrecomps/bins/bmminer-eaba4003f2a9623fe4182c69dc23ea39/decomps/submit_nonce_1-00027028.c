
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

_Bool submit_nonce_1(thr_info *thr,work *work,uint nonce,int *nofull)

{
  _Bool _Var1;
  int *nofull_local;
  uint nonce_local;
  work *work_local;
  thr_info *thr_local;
  char tmp42 [2048];
  
  if (nofull != (int *)0x0) {
    *nofull = 0;
  }
  _Var1 = test_nonce(work,nonce);
  if (_Var1) {
    update_work_stats(thr,work);
    _Var1 = fulltest(work->hash,work->target);
    if (_Var1) {
      _Var1 = true;
    }
    else {
      if (nofull != (int *)0x0) {
        *nofull = 1;
      }
      if (((use_syslog != false) || (opt_log_output != false)) || (5 < opt_log_level)) {
        tmp42[0] = s_Share_above_target_00074224[0];
        tmp42[1] = s_Share_above_target_00074224[1];
        tmp42[2] = s_Share_above_target_00074224[2];
        tmp42[3] = s_Share_above_target_00074224[3];
        tmp42[4] = s_Share_above_target_00074224[4];
        tmp42[5] = s_Share_above_target_00074224[5];
        tmp42[6] = s_Share_above_target_00074224[6];
        tmp42[7] = s_Share_above_target_00074224[7];
        tmp42[8] = s_Share_above_target_00074224[8];
        tmp42[9] = s_Share_above_target_00074224[9];
        tmp42[10] = s_Share_above_target_00074224[10];
        tmp42[11] = s_Share_above_target_00074224[11];
        tmp42[12] = s_Share_above_target_00074224[12];
        tmp42[13] = s_Share_above_target_00074224[13];
        tmp42[14] = s_Share_above_target_00074224[14];
        tmp42[15] = s_Share_above_target_00074224[15];
        tmp42._16_2_ = (undefined2)ram0x00074234;
        tmp42[18] = (char)((uint)ram0x00074234 >> 0x10);
        _applog(6,tmp42,false);
      }
      _Var1 = false;
    }
  }
  else {
    inc_hw_errors(thr);
    _Var1 = false;
  }
  return _Var1;
}

