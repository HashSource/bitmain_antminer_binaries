
undefined4
ISL_get_voltage(undefined1 param_1,undefined1 param_2,undefined1 param_3,undefined2 *param_4)

{
  undefined2 local_c [2];
  
  memset(local_c,0,2);
  read_dc_dc(param_1,param_2,param_3,0x21,local_c,2);
  *param_4 = local_c[0];
  return 0;
}

