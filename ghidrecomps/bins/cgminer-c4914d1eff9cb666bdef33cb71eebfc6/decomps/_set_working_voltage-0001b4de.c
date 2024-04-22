
/* WARNING: Variable defined which should be unmapped: volt-local */

void _set_working_voltage(double volt)

{
  _Bool _Var1;
  double in_d0;
  double volt_local;
  int _chain;
  
  pthread_mutex_lock((pthread_mutex_t *)&set_voltage_lock);
  set_voltage_flag = true;
  pthread_mutex_unlock((pthread_mutex_t *)&set_voltage_lock);
  _Var1 = is_T11();
  if (_Var1) {
    for (_chain = 0; _chain < 0x10; _chain = _chain + 1) {
      if (dev->chain_exist[_chain] != 0) {
        set_working_voltage_by_chain((uint8_t)_chain,in_d0);
      }
    }
  }
  else {
    set_working_voltage(in_d0);
  }
  pthread_mutex_lock((pthread_mutex_t *)&set_voltage_lock);
  set_voltage_flag = false;
  pthread_mutex_unlock((pthread_mutex_t *)&set_voltage_lock);
  return;
}

