
/* WARNING: Unknown calling convention */

_Bool is_column_sweep(void)

{
  _Bool _Var1;
  
  _Var1 = is_T11();
  if (_Var1) {
    if ((g_device_minor_type == PKG_BSL) || (g_device_minor_type == PKG_B_BGM)) {
      _Var1 = false;
    }
    else {
      _Var1 = true;
    }
  }
  else {
    _Var1 = false;
  }
  return _Var1;
}

