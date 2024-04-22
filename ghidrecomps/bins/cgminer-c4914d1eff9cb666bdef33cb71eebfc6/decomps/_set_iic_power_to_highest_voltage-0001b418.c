
/* WARNING: Unknown calling convention */

int _set_iic_power_to_highest_voltage(void)

{
  _Bool _Var1;
  uint uVar2;
  int ret;
  int _chain;
  
  ret = 0;
  pthread_mutex_lock((pthread_mutex_t *)&set_voltage_lock);
  set_voltage_flag = true;
  pthread_mutex_unlock((pthread_mutex_t *)&set_voltage_lock);
  _Var1 = is_T11();
  if (_Var1) {
    for (_chain = 0; _chain < 0x10; _chain = _chain + 1) {
      if (dev->chain_exist[_chain] != 0) {
        _Var1 = set_iic_power_to_highest_voltage_by_chain((int8_t)_chain);
        if (_Var1) {
          uVar2 = 0;
        }
        else {
          uVar2 = 0xffffffff;
        }
        ret = uVar2 | ret;
      }
    }
  }
  else {
    _Var1 = set_iic_power_to_highest_voltage();
    if (_Var1) {
      ret = 0;
    }
    else {
      ret = -1;
    }
  }
  pthread_mutex_lock((pthread_mutex_t *)&set_voltage_lock);
  set_voltage_flag = false;
  pthread_mutex_unlock((pthread_mutex_t *)&set_voltage_lock);
  return ret;
}

