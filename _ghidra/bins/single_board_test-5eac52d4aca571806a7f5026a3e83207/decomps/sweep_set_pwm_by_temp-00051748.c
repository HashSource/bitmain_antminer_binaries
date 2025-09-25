
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void sweep_set_pwm_by_temp(void)

{
  int temp_00;
  int32_t temp;
  
  temp_00 = pf_get_max_value(g_rt.tempval,((g_rt.config)->board).sensor.sensor_num);
  set_pwm_by_temp(temp_00);
  return;
}

