
undefined * get_reg_auto_test(undefined param_1)

{
  undefined *puVar1;
  undefined local_10;
  undefined local_f;
  undefined local_e;
  undefined4 local_c;
  
  local_f = 1;
  local_10 = 0;
  local_c = 0;
  puVar1 = &local_10;
  local_e = param_1;
  midd_ioctl(g_chain._0_4_,0,puVar1);
  usleep(300000);
  return puVar1;
}

