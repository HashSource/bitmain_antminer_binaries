
undefined4
iic_read_reg(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = pthread_mutex_lock((pthread_mutex_t *)&iic_mutex);
  if (iVar1 == 0) {
    uVar2 = i2c_read_reg(param_1,param_2,param_3,param_4,param_5);
    pthread_mutex_unlock((pthread_mutex_t *)&iic_mutex);
  }
  else {
    printf("%s:%d","iic_read_reg",0x7b);
    puts("failed to i2c lock");
    uVar2 = 0xfffffffc;
  }
  return uVar2;
}

