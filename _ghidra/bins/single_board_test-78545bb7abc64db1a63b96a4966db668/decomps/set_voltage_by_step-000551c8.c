
_Bool set_voltage_by_step(uint32_t pre_voltage,uint32_t target_voltage,uint8_t step_num)

{
  _Bool _Var1;
  uint8_t step_num_local;
  uint32_t target_voltage_local;
  uint32_t pre_voltage_local;
  
  _Var1 = set_pattern_test_voltage_by_step(pre_voltage,target_voltage,step_num);
  return _Var1;
}

