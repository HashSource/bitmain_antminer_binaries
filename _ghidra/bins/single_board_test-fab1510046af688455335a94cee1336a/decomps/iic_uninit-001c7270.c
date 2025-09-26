
/* WARNING: Unknown calling convention */

void iic_uninit(int32_t ctx)

{
  int iVar1;
  char tmp42 [2048];
  
  iVar1 = pthread_mutex_lock((pthread_mutex_t *)&iic_mutex);
  if (iVar1 == 0) {
    i2c_uninit(ctx);
    pthread_mutex_unlock((pthread_mutex_t *)&iic_mutex);
    return;
  }
  builtin_strncpy(tmp42,"failed to i2c lock\n",0x14);
  _applog(0,tmp42,false);
  return;
}

