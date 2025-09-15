
/* WARNING: Unknown calling convention */

float get_max_freq(void)

{
  _Bool _Var1;
  float fVar2;
  
  _Var1 = is_economic_mode();
  if (_Var1) {
    _Var1 = is_economic_mode();
    fVar2 = get_max_scanfreq(_Var1);
    fVar2 = fVar2 + 10.0;
  }
  else {
    _Var1 = is_economic_mode();
    fVar2 = get_max_scanfreq(_Var1);
  }
  return fVar2;
}

