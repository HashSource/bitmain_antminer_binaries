
/* WARNING: Variable defined which should be unmapped: target_vol-local */

_Bool slowly_adapt_voltage(power_info_t *power,double target_vol,uint32_t ms_delay)

{
  uint uVar1;
  char cVar2;
  char cVar3;
  byte target_data;
  _Bool _Var4;
  int iVar5;
  double in_d0;
  double target_vol_local;
  uint32_t ms_delay_local;
  power_info_t *power_local;
  uint8_t threshold_iic_data;
  uint8_t target_iic_data;
  _Bool ret;
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
  if (power->current_voltage < in_d0) {
    negate = -1;
  }
  else {
    negate = 1;
  }
  temp_iic_data = get_power_iic_value_from_voltage(in_d0);
  target_data = get_power_iic_value_from_voltage(in_d0);
  uVar1 = (int)((uint)temp_iic_data - (uint)target_data) >> 0x1f;
  iVar5 = ((uint)temp_iic_data - (uint)target_data ^ uVar1) - uVar1;
  cVar2 = (char)((ulonglong)((longlong)iVar5 * 0x2aaaaaab) >> 0x20) - (char)(iVar5 >> 0x1f);
  target_vol_local._0_4_ = SUB84(in_d0,0);
  target_vol_local._4_4_ = (undefined4)((ulonglong)in_d0 >> 0x20);
  if (negate == -1) {
    _Var4 = set_iic_power_by_voltage(in_d0,power);
    *(undefined4 *)&power->current_voltage = target_vol_local._0_4_;
    *(undefined4 *)((int)&power->current_voltage + 4) = target_vol_local._4_4_;
    power->current_iic_data = target_data;
    return _Var4;
  }
  for (; cVar3 = (char)negate, i < 5; i = i + 1) {
    temp_iic_data = temp_iic_data + cVar2 * cVar3;
    _Var4 = set_iic_power_by_iic_data(temp_iic_data,power);
    if (!_Var4) {
      return false;
    }
    usleep(sleep_ms * 500);
    if (cVar2 == '\0') break;
  }
  while( true ) {
    while( true ) {
      iVar5 = (uint)temp_iic_data - (uint)target_data;
      if (iVar5 < 0) {
        iVar5 = -iVar5;
      }
      if ((byte)iVar5 < 0x21) {
        if ((byte)iVar5 < 0x11) {
          diff_iic_data = '\x02';
        }
        else {
          diff_iic_data = '\b';
        }
      }
      else {
        diff_iic_data = '\x10';
      }
      iVar5 = (uint)temp_iic_data - (uint)target_data;
      if (iVar5 < 0) {
        iVar5 = -iVar5;
      }
      if (iVar5 < 3) break;
      temp_iic_data = temp_iic_data + diff_iic_data * cVar3;
      _Var4 = set_iic_power_by_iic_data(temp_iic_data,power);
      if (!_Var4) {
        return false;
      }
      usleep(sleep_ms * 500);
    }
    iVar5 = (uint)temp_iic_data - (uint)target_data;
    if (iVar5 < 0) {
      iVar5 = -iVar5;
    }
    if (iVar5 < 2) break;
    temp_iic_data = temp_iic_data + cVar3;
    _Var4 = set_iic_power_by_iic_data(temp_iic_data,power);
    if (!_Var4) {
      return false;
    }
    usleep(sleep_ms * 500);
  }
  _Var4 = set_iic_power_by_iic_data(target_data,power);
  if (!_Var4) {
    return false;
  }
  usleep(sleep_ms * 500);
  *(undefined4 *)&power->current_voltage = target_vol_local._0_4_;
  *(undefined4 *)((int)&power->current_voltage + 4) = target_vol_local._4_4_;
  power->current_iic_data = target_data;
  return _Var4;
}

