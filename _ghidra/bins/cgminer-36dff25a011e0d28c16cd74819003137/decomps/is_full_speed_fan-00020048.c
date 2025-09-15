
/* WARNING: Unknown calling convention */

_Bool is_full_speed_fan(void)

{
  _Bool _Var1;
  
  if ((1 < dev->temp_air_in_bad_count) || (_Var1 = temp_is_air_out_too_high(), _Var1)) {
    _Var1 = true;
  }
  else {
    _Var1 = false;
  }
  return _Var1;
}

