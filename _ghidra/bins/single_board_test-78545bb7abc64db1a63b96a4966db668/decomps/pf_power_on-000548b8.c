
_Bool pf_power_on(uint32_t voltage)

{
  _Bool _Var1;
  uint32_t voltage_local;
  _Bool ret;
  
  _Var1 = APW_power_on(voltage);
  return _Var1;
}

