
/* WARNING: Variable defined which should be unmapped: ms_delay-local */

_Bool slowly_adapt_voltage(double target_vol,uint32_t ms_delay)

{
  uint uVar1;
  byte target_data;
  _Bool _Var2;
  int iVar3;
  double in_d0;
  undefined4 uStack_30;
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
  if ((double)CONCAT44(power_info.current_voltage._4_4_,power_info.current_voltage._0_4_) < in_d0) {
    negate._0_1_ = -1;
  }
  else {
    negate._0_1_ = '\x01';
  }
  temp_iic_data = get_power_iic_value_from_voltage((double)CONCAT44(ms_delay,uStack_30));
  target_data = get_power_iic_value_from_voltage((double)CONCAT44(ms_delay,uStack_30));
  uVar1 = (int)((uint)temp_iic_data - (uint)target_data) >> 0x1f;
  iVar3 = ((uint)temp_iic_data - (uint)target_data ^ uVar1) - uVar1;
  for (; i < 5; i = i + 1) {
    temp_iic_data =
         ((char)((ulonglong)((longlong)iVar3 * 0x2aaaaaab) >> 0x20) - (char)(iVar3 >> 0x1f)) *
         (char)negate + temp_iic_data;
    _Var2 = set_iic_power_by_iic_data(temp_iic_data,&power_info);
    if (!_Var2) {
      return false;
    }
    usleep(sleep_ms * 500);
  }
  while( true ) {
    while( true ) {
      iVar3 = (uint)temp_iic_data - (uint)target_data;
      if (iVar3 < 0) {
        iVar3 = -iVar3;
      }
      if ((byte)iVar3 < 0x21) {
        if ((byte)iVar3 < 0x11) {
          diff_iic_data = '\x02';
        }
        else {
          diff_iic_data = '\b';
        }
      }
      else {
        diff_iic_data = '\x10';
      }
      iVar3 = (uint)temp_iic_data - (uint)target_data;
      if (iVar3 < 0) {
        iVar3 = -iVar3;
      }
      if (iVar3 < 3) break;
      temp_iic_data = diff_iic_data * (char)negate + temp_iic_data;
      _Var2 = set_iic_power_by_iic_data(temp_iic_data,&power_info);
      if (!_Var2) {
        return false;
      }
      usleep(sleep_ms * 500);
    }
    iVar3 = (uint)temp_iic_data - (uint)target_data;
    if (iVar3 < 0) {
      iVar3 = -iVar3;
    }
    if (iVar3 < 2) break;
    temp_iic_data = (char)negate + temp_iic_data;
    _Var2 = set_iic_power_by_iic_data(temp_iic_data,&power_info);
    if (!_Var2) {
      return false;
    }
    usleep(sleep_ms * 500);
  }
  _Var2 = set_iic_power_by_iic_data(target_data,&power_info);
  if (!_Var2) {
    return false;
  }
  usleep(sleep_ms * 500);
  target_vol_local._0_4_ = SUB84(in_d0,0);
  target_vol_local._4_4_ = (undefined4)((ulonglong)in_d0 >> 0x20);
  power_info.current_voltage._0_4_ = target_vol_local._0_4_;
  power_info.current_voltage._4_4_ = target_vol_local._4_4_;
  power_info.current_iic_data = target_data;
  return _Var2;
}

