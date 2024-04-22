
/* WARNING: Unknown calling convention */

void * quit_thread(void *userdata)

{
  int iVar1;
  char *in_r2;
  int in_r3;
  char tmp42 [2048];
  
  iVar1 = pthread_mutex_lock(DAT_0001955c);
  if (iVar1 != 0) {
    _mutex_lock(DAT_00019578,(char *)0x1355,in_r2,in_r3);
  }
  iVar1 = pthread_mutex_unlock(DAT_0001955c);
  if (iVar1 != 0) {
    _mutex_unlock_noyield(DAT_00019578,(char *)0x1356,in_r2,in_r3);
  }
  (**DAT_00019560)();
  if ((*DAT_00019564 != '\0') &&
     (((*DAT_00019568 != '\0' || (*DAT_0001956c != '\0')) || (6 < *DAT_00019574)))) {
    tmp42._0_4_ = *DAT_00019570;
    tmp42._4_4_ = DAT_00019570[1];
    tmp42._8_4_ = DAT_00019570[2];
    tmp42._12_4_ = DAT_00019570[3];
    tmp42._16_4_ = DAT_00019570[4];
    tmp42[20] = (char)DAT_00019570[5];
    _applog(7,tmp42,false);
  }
  kill_work();
  return (void *)0x0;
}

