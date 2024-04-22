
void write_sensor_info_into_pic(undefined4 param_1,undefined param_2)

{
  undefined local_10;
  undefined local_f;
  undefined local_e;
  undefined local_d;
  undefined local_c;
  undefined local_b;
  byte local_a;
  undefined local_9;
  
  local_10 = 0;
  local_f = 0;
  local_e = 0;
  local_d = 0;
  local_c = 0;
  local_b = 0;
  local_a = 0;
  local_9 = 0;
  printf("\n--- %s\n","write_sensor_info_into_pic");
  local_10 = Conf[220];
  local_f = 0;
  local_e = Conf[221];
  local_d = 0;
  local_c = Conf[222];
  local_b = 0;
  local_a = Conf[248] | 0x20;
  local_9 = (undefined)Conf._252_4_;
  set_temperature_offset_value(param_1,param_2,&local_10);
  return;
}

