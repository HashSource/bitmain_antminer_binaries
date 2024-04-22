
undefined4
ISL_set_write_protect(undefined param_1,undefined param_2,undefined param_3,undefined param_4)

{
  undefined local_14;
  undefined local_13;
  undefined local_12;
  undefined local_11;
  
  local_14 = param_4;
  local_13 = param_3;
  local_12 = param_2;
  local_11 = param_1;
  write_dc_dc(param_1,param_2,param_3,0x10,&local_14,1);
  return 0;
}

