
/* WARNING: Unknown calling convention */

void inc_hw_errors(thr_info *thr)

{
  pthread_mutex_t *__mutex;
  int iVar1;
  char *in_r2;
  cgpu_info *func;
  char *line;
  int *line_00;
  char tmp42 [2048];
  
  if (((*DAT_000207cc != '\0') || (*DAT_000207d0 != '\0')) || (line = *DAT_000207e4, 5 < (int)line))
  {
    line = thr->cgpu->drv->name;
    snprintf(tmp42,0x800,DAT_000207d4,line,thr->cgpu->device_id);
    in_r2 = (char *)0x0;
    _applog(6,tmp42,false);
  }
  iVar1 = pthread_mutex_lock(DAT_000207d8);
  if (iVar1 != 0) {
    _mutex_lock(DAT_000207e8,(char *)0x21ba,in_r2,(int)line);
  }
  line_00 = DAT_000207dc;
  __mutex = DAT_000207d8;
  func = thr->cgpu;
  iVar1 = *DAT_000207dc;
  func->hw_errors = func->hw_errors + 1;
  *line_00 = iVar1 + 1;
  iVar1 = pthread_mutex_unlock(__mutex);
  if (iVar1 != 0) {
    _mutex_unlock_noyield(DAT_000207e8,(char *)0x21bd,(char *)func,(int)line_00);
  }
  (**DAT_000207e0)();
  (*thr->cgpu->drv->hw_error)(thr);
  return;
}

