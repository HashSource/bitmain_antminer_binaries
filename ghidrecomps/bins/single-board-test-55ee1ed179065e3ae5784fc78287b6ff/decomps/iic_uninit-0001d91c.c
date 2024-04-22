
void iic_uninit(undefined4 param_1)

{
  int iVar1;
  
  iVar1 = pthread_mutex_lock((pthread_mutex_t *)&iic_mutex);
  if (iVar1 == 0) {
    i2c_uninit(param_1);
    pthread_mutex_unlock((pthread_mutex_t *)&iic_mutex);
  }
  else {
    printf("%s:%d","iic_uninit",0x3f);
    puts("failed to i2c lock");
  }
  return;
}

