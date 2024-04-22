
/* WARNING: Unknown calling convention */

void _slowly_set_iic_power_to_working_voltage(void)

{
  _Bool _Var1;
  
  pthread_mutex_lock((pthread_mutex_t *)&set_voltage_lock);
  set_voltage_flag = true;
  pthread_mutex_unlock((pthread_mutex_t *)&set_voltage_lock);
  _Var1 = is_T11();
  if (_Var1) {
    slowly_set_iic_power_voltage_t11(1);
  }
  else {
    slowly_set_iic_power_to_working_voltage();
  }
  pthread_mutex_lock((pthread_mutex_t *)&set_voltage_lock);
  set_voltage_flag = false;
  pthread_mutex_unlock((pthread_mutex_t *)&set_voltage_lock);
  return;
}

