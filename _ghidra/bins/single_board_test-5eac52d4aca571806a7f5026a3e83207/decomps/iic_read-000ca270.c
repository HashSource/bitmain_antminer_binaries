
/* WARNING: Unknown calling convention */

int32_t iic_read(int32_t ctx,void *data,uint32_t size)

{
  int iVar1;
  int32_t iVar2;
  char tmp42 [2048];
  
  iVar1 = pthread_mutex_lock((pthread_mutex_t *)&iic_mutex);
  if (iVar1 == 0) {
    iVar2 = i2c_read(ctx,data,size);
    pthread_mutex_unlock((pthread_mutex_t *)&iic_mutex);
  }
  else {
    iVar2 = -4;
    builtin_strncpy(tmp42,"failed to i2c lock\n",0x14);
    _applog(0,tmp42,false);
  }
  return iVar2;
}

