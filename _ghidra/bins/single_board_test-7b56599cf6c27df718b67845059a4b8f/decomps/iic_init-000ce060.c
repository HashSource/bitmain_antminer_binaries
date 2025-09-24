
/* WARNING: Unknown calling convention */

int32_t iic_init(iic_init_param_t *param)

{
  int iVar1;
  int32_t ctx;
  int32_t iVar2;
  char tmp42 [2048];
  
  iVar1 = pthread_mutex_lock((pthread_mutex_t *)&iic_mutex);
  if (iVar1 != 0) {
    builtin_strncpy(tmp42,"failed to iic lock\n",0x14);
    _applog(0,tmp42,false);
    return -4;
  }
  if (param == (iic_init_param_t *)0x0) {
    ctx = -3;
    builtin_strncpy(tmp42,"bad para",8);
    tmp42[8] = 'm';
    tmp42[9] = '\n';
    tmp42[10] = '\0';
    _applog(0,tmp42,false);
  }
  else {
    ctx = i2c_init((int8_t *)0x0);
    if (ctx < 0) {
      ctx = -1;
      builtin_strncpy(tmp42,"failed to i2c_init\n",0x14);
      _applog(0,tmp42,false);
    }
    else {
      iVar2 = i2c_select(ctx,(uint)param->master_addr);
      if (iVar2 == 0) {
        iVar2 = i2c_ioctl(ctx,0x703,(uint)param->slave_low << 1 | (uint)param->slave_high << 4);
        if (iVar2 == 0) goto LAB_000ce0c2;
        builtin_strncpy(tmp42,"failed to i2c_ioctl\n",0x14);
        tmp42._20_2_ = tmp42._20_2_ & 0xff00;
        _applog(0,tmp42,false);
      }
      else {
        builtin_strncpy(tmp42,"failed to i2c_select",0x14);
        tmp42[0x14] = '\n';
        tmp42[0x15] = '\0';
        _applog(0,tmp42,false);
      }
      if (ctx == 0) {
        ctx = -1;
      }
      else {
        i2c_uninit(ctx);
        ctx = -1;
      }
    }
  }
LAB_000ce0c2:
  pthread_mutex_unlock((pthread_mutex_t *)&iic_mutex);
  return ctx;
}

