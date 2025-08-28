
undefined4 def_init_WIN32(undefined4 *param_1)

{
  if (param_1 != (undefined4 *)0x0) {
    param_1[2] = 0;
    *param_1 = WIN32_method;
    param_1[1] = CONF_type_win32;
    return 1;
  }
  return 0;
}

