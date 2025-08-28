
undefined4 def_init_default(undefined4 *param_1)

{
  if (param_1 != (undefined4 *)0x0) {
    param_1[2] = 0;
    *param_1 = &default_method;
    param_1[1] = CONF_type_default;
    return 1;
  }
  return 0;
}

