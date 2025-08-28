
undefined4 ISL_read_reg_default(undefined1 param_1,undefined1 param_2,undefined1 param_3)

{
  undefined1 local_c;
  undefined1 local_b;
  
  local_c = 0;
  local_b = 0;
  read_dc_dc(param_1,param_2,param_3,0,&local_c,1);
  read_dc_dc(param_1,param_2,param_3,1,&local_c,1);
  read_dc_dc(param_1,param_2,param_3,2,&local_c,1);
  read_dc_dc(param_1,param_2,param_3,3,&local_c,1);
  read_dc_dc(param_1,param_2,param_3,0x10,&local_c,1);
  read_dc_dc(param_1,param_2,param_3,0x21,&local_c,2);
  read_dc_dc(param_1,param_2,param_3,0x22,&local_c,1);
  return 0;
}

