
/* WARNING: Unknown calling convention */

void * restart_thread(void *userdata)

{
  int iVar1;
  char *in_r2;
  int in_r3;
  char tmp42 [2048];
  
  iVar1 = pthread_mutex_lock(DAT_000194bc);
  if (iVar1 != 0) {
    _mutex_lock(DAT_000194d8,(char *)0x1363,in_r2,in_r3);
  }
  iVar1 = pthread_mutex_unlock(DAT_000194bc);
  if (iVar1 != 0) {
    _mutex_unlock_noyield(DAT_000194d8,(char *)0x1364,in_r2,in_r3);
  }
  (**DAT_000194c0)();
  if ((*DAT_000194c4 != '\0') &&
     (((*DAT_000194c8 != '\0' || (*DAT_000194cc != '\0')) || (6 < *DAT_000194d4)))) {
    tmp42._0_4_ = *DAT_000194d0;
    tmp42._4_4_ = DAT_000194d0[1];
    tmp42._8_4_ = DAT_000194d0[2];
    tmp42._12_4_ = DAT_000194d0[3];
    tmp42._16_4_ = DAT_000194d0[4];
    tmp42._20_4_ = DAT_000194d0[5];
    _applog(7,tmp42,false);
  }
  app_restart();
  return (void *)0x0;
}

