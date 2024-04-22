
ushort ISL_set_voltage(undefined param_1,undefined param_2,undefined param_3,undefined2 param_4)

{
  ushort local_14;
  byte local_12;
  byte local_11;
  
  puts("begin to read voltage");
  ISL_page_enable(param_1,param_2,param_3,0);
  usleep(100000);
  usleep(100000);
  ISL_set_vout_command(param_1,param_2,param_3,param_4);
  usleep(100000);
  usleep(100000);
  puts("end to read voltage");
  local_11 = 0;
  local_12 = 5;
  local_14 = 0;
  do {
    usleep(100000);
    ISL_get_voltage(param_1,param_2,param_3,&local_14);
    local_11 = local_11 + 1;
    if (local_12 < local_11) break;
  } while (local_14 == 0);
  printf("--- ISL_get_voltage, Voltage: 0.%03d V\n\n",(uint)local_14);
  return local_14;
}

