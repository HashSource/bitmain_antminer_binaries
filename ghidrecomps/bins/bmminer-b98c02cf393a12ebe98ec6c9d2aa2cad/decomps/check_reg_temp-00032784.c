
uint check_reg_temp(undefined4 param_1,uint param_2,uint param_3,int param_4,undefined1 param_5,
                   undefined4 param_6)

{
  uint uVar1;
  int iVar2;
  
  pthread_mutex_lock((pthread_mutex_t *)temp_mutex);
  if (param_4 == 0) {
    iVar2 = 0;
    do {
      iVar2 = iVar2 + 1;
      wait_iic_ok(param_5,param_6,0);
      read_temp(param_1,param_2,param_3,0,param_5,param_6);
      cgsleep_ms(1);
      uVar1 = wait_iic_ok(param_5,param_6,1);
      cgsleep_ms(1);
      if ((param_2 == (uVar1 << 0x10) >> 0x18) && ((uVar1 & 0x7f) != 0x7f)) {
LAB_0003286a:
        pthread_mutex_unlock((pthread_mutex_t *)temp_mutex);
        if (iVar2 != 2) {
          return uVar1;
        }
        return 0;
      }
    } while (iVar2 == 1);
  }
  else {
    iVar2 = 0;
    do {
      iVar2 = iVar2 + 1;
      wait_iic_ok(param_5,param_6,0);
      read_temp(param_1,param_2,param_3,param_4,param_5,param_6);
      wait_iic_ok(param_5,param_6,1);
      cgsleep_ms(1);
      wait_iic_ok(param_5,param_6,0);
      read_temp(param_1,param_2,0,0,param_5,param_6);
      uVar1 = wait_iic_ok(param_5,param_6,1);
      cgsleep_ms(1);
      if ((param_2 == (uVar1 << 0x10) >> 0x18) || ((uVar1 & 0xff) == param_3)) goto LAB_0003286a;
    } while (iVar2 == 1);
  }
  pthread_mutex_unlock((pthread_mutex_t *)temp_mutex);
  return 0;
}

