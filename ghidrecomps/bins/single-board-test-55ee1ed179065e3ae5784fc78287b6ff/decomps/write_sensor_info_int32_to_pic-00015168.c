
void write_sensor_info_int32_to_pic(undefined4 param_1,undefined1 param_2)

{
  undefined1 local_10;
  undefined1 local_f;
  undefined1 local_e;
  undefined1 local_d;
  undefined1 local_c;
  undefined1 local_b;
  byte local_a;
  undefined1 local_9;
  
  local_10 = 0;
  local_f = 0;
  local_e = 0;
  local_d = 0;
  local_c = 0;
  local_b = 0;
  local_a = 0;
  local_9 = 0;
  printf("\n--- %s\n","write_sensor_info_int32_to_pic");
  local_10 = Conf[0xd0];
  local_f = 0;
  local_e = Conf[0xd1];
  local_d = 0;
  local_c = Conf[0xd2];
  local_b = 0;
  local_a = Conf[0xfc] | 0x20;
  local_9 = (undefined1)Conf._256_4_;
  set_temperature_offset_value(param_1,param_2,&local_10);
  return;
}

