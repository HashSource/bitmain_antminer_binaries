
/* WARNING: Unknown calling convention */

_Bool is_in_error(void)

{
  _Bool _Var1;
  
  if ((fatal_error_counter < 1) || (status_value < ERROR_NETCONN_LOST)) {
    _Var1 = false;
  }
  else {
    _Var1 = true;
  }
  return _Var1;
}

