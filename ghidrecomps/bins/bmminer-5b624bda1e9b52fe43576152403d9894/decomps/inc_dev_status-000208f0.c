
/* WARNING: Unknown calling convention */

void inc_dev_status(int max_fan,int max_temp)

{
  pthread_mutex_t *__mutex;
  int iVar1;
  char *in_r2;
  int *func;
  int in_r3;
  int *line;
  
  iVar1 = pthread_mutex_lock(DAT_00020930);
  if (iVar1 != 0) {
    _mutex_lock(DAT_00020940,(char *)0x21d3,in_r2,in_r3);
  }
  line = DAT_00020938;
  func = DAT_00020934;
  __mutex = DAT_00020930;
  *DAT_00020934 = max_fan;
  *line = max_temp;
  iVar1 = pthread_mutex_unlock(__mutex);
  if (iVar1 != 0) {
    _mutex_unlock_noyield(DAT_00020940,(char *)0x21d6,(char *)func,(int)line);
  }
  (**DAT_0002093c)();
  return;
}

