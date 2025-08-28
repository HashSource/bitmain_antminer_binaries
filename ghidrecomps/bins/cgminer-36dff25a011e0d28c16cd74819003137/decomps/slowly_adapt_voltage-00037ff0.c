
_Bool slowly_adapt_voltage(double target_vol,uint32_t ms_delay)

{
  uint uVar1;
  double dVar2;
  byte target_data;
  _Bool _Var3;
  int iVar4;
  uint32_t ms_delay_local;
  double target_vol_local;
  _Bool ret;
  uint8_t threshold_iic_data;
  uint8_t target_iic_data;
  power_info_t *power;
  uint8_t diff_iic_data;
  uint8_t temp_iic_data;
  int negate;
  int sleep_ms;
  int i;
  
  i = 0;
  sleep_ms = ms_delay;
  if (ms_delay == 0) {
    sleep_ms = 1000;
  }
  if (power_info.current_voltage < target_vol) {
    negate._0_1_ = -1;
  }
  else {
    negate._0_1_ = '\x01';
  }
  temp_iic_data = get_power_iic_value_from_voltage(power_info.current_voltage);
  target_data = get_power_iic_value_from_voltage(target_vol);
  uVar1 = (int)((uint)temp_iic_data - (uint)target_data) >> 0x1f;
  iVar4 = ((uint)temp_iic_data - (uint)target_data ^ uVar1) - uVar1;
  for (; i < 5; i = i + 1) {
    temp_iic_data =
         ((char)((ulonglong)((longlong)iVar4 * 0x2aaaaaab) >> 0x20) - (char)(iVar4 >> 0x1f)) *
         (char)negate + temp_iic_data;
    _Var3 = set_iic_power_by_iic_data(temp_iic_data,&power_info);
    if (!_Var3) {
      _Var3 = false;
      dVar2 = power_info.current_voltage;
      goto LAB_00038314;
    }
    usleep(sleep_ms * 500);
  }
  while( true ) {
    while( true ) {
      iVar4 = (uint)temp_iic_data - (uint)target_data;
      if (iVar4 < 0) {
        iVar4 = -iVar4;
      }
      if ((byte)iVar4 < 0x21) {
        if ((byte)iVar4 < 0x11) {
          diff_iic_data = '\x02';
        }
        else {
          diff_iic_data = '\b';
        }
      }
      else {
        diff_iic_data = '\x10';
      }
      iVar4 = (uint)temp_iic_data - (uint)target_data;
      if (iVar4 < 0) {
        iVar4 = -iVar4;
      }
      if (iVar4 < 3) break;
      temp_iic_data = diff_iic_data * (char)negate + temp_iic_data;
      _Var3 = set_iic_power_by_iic_data(temp_iic_data,&power_info);
      if (!_Var3) {
        _Var3 = false;
        dVar2 = power_info.current_voltage;
        goto LAB_00038314;
      }
      usleep(sleep_ms * 500);
    }
    iVar4 = (uint)temp_iic_data - (uint)target_data;
    if (iVar4 < 0) {
      iVar4 = -iVar4;
    }
    if (iVar4 < 2) break;
    temp_iic_data = (char)negate + temp_iic_data;
    _Var3 = set_iic_power_by_iic_data(temp_iic_data,&power_info);
    if (!_Var3) {
      _Var3 = false;
      dVar2 = power_info.current_voltage;
LAB_00038314:
      power_info.current_voltage._4_4_ = (undefined4)((ulonglong)dVar2 >> 0x20);
      power_info.current_voltage._0_4_ = SUB84(dVar2,0);
      return _Var3;
    }
    usleep(sleep_ms * 500);
  }
  _Var3 = set_iic_power_by_iic_data(target_data,&power_info);
  if (_Var3) {
    usleep(sleep_ms * 500);
    power_info.current_iic_data = target_data;
    dVar2 = target_vol;
  }
  else {
    _Var3 = false;
    dVar2 = power_info.current_voltage;
  }
  goto LAB_00038314;
}

