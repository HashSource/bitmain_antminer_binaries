
/* WARNING: Unknown calling convention */

_Bool submit_tested_work(thr_info *thr,work *work)

{
  _Bool _Var1;
  work *work_00;
  char tmp42 [2048];
  
  update_work_stats(thr,work);
  _Var1 = fulltest(work->hash,work->target);
  if (_Var1) {
    work_00 = copy_work_noffset(work,0);
    submit_work_async(work_00);
    _Var1 = true;
  }
  else if (((*DAT_00029890 != '\0') || (*DAT_00029894 != '\0')) ||
          (_Var1 = false, 5 < *DAT_00029898)) {
    snprintf(tmp42,0x800,DAT_0002989c,DAT_000298a0,thr->cgpu->drv->name,thr->cgpu->device_id);
    _applog(6,tmp42,false);
    _Var1 = false;
  }
  return _Var1;
}

