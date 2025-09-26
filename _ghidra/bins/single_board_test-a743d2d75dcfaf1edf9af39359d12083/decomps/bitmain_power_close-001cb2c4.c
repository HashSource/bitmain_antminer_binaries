
/* WARNING: Unknown calling convention */

int32_t bitmain_power_close(void)

{
  int iVar1;
  char tmp42 [2048];
  
  pthread_mutex_lock((pthread_mutex_t *)&power_mutex);
  builtin_strncpy(tmp42,"bitmain power close ===========\n",0x20);
  tmp42[0x20] = '\0';
  _applog(3,tmp42,false);
  iic_uninit(_g_power_state.power_fd);
  memset(&_g_power_state,0,0x170);
  iVar1 = pthread_mutex_unlock((pthread_mutex_t *)&power_mutex);
  return iVar1;
}

