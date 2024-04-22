
/* WARNING: Unknown calling convention */

void inc_hw_errors_with_diff(thr_info *thr,int diff)

{
  pthread_mutex_t *__mutex;
  int iVar1;
  char *in_r2;
  cgpu_info *func;
  char *line;
  int *line_00;
  char tmp42 [2048];
  
  if (((*DAT_00020880 != '\0') || (*DAT_00020884 != '\0')) || (line = *DAT_00020898, 2 < (int)line))
  {
    line = thr->cgpu->drv->name;
    snprintf(tmp42,0x800,DAT_00020888,line,thr->cgpu->device_id);
    in_r2 = (char *)0x0;
    _applog(3,tmp42,false);
  }
  iVar1 = pthread_mutex_lock(DAT_0002088c);
  if (iVar1 != 0) {
    _mutex_lock(DAT_0002089c,(char *)0x21c7,in_r2,(int)line);
  }
  line_00 = DAT_00020890;
  __mutex = DAT_0002088c;
  func = thr->cgpu;
  iVar1 = *DAT_00020890;
  func->hw_errors = func->hw_errors + diff;
  *line_00 = iVar1 + diff;
  iVar1 = pthread_mutex_unlock(__mutex);
  if (iVar1 != 0) {
    _mutex_unlock_noyield(DAT_0002089c,(char *)0x21ca,(char *)func,(int)line_00);
  }
  (**DAT_00020894)();
  (*thr->cgpu->drv->hw_error)(thr);
  return;
}

