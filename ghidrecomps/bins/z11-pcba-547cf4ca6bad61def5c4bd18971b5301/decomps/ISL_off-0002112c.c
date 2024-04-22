
undefined4 ISL_off(undefined param_1,undefined param_2,undefined param_3)

{
  undefined local_9;
  
  local_9 = 0x40;
  write_dc_dc(param_1,param_2,param_3,1,&local_9,1);
  return 0;
}

