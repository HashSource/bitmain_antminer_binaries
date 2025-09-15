
/* WARNING: Unknown calling convention */

_Bool aging_is_bad_machine(void)

{
  _Bool _Var1;
  
  if ((!aging_info.is_bad_machine) || (aging_info.aging_24_hour_finished)) {
    _Var1 = false;
  }
  else {
    _Var1 = true;
  }
  return _Var1;
}

