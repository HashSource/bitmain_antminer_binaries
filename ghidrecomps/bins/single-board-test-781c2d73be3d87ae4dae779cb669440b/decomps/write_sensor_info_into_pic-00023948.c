
/* WARNING: Unknown calling convention */

void write_sensor_info_into_pic(uint which_i2c,uchar which_chain)

{
  uchar offset_value [8];
  
  offset_value[4] = '\0';
  offset_value[5] = '\0';
  offset_value[6] = '\0';
  offset_value[7] = '\0';
  offset_value[0] = '\0';
  offset_value[1] = '\0';
  offset_value[2] = '\0';
  offset_value[3] = '\0';
  printf("\n--- %s\n",DAT_000239b4);
  offset_value._4_3_ = (uint3)(byte)Conf.sensor_model << 0x10 | 0x200000;
  offset_value[1] = '\0';
  offset_value[0] = (byte)Conf.TempSensor1;
  offset_value[2] = (uchar)Conf.TempSensor2;
  offset_value[3] = '\0';
  offset_value[7] = (uchar)Conf.remote_local_gap;
  offset_value._4_3_ = (int3)CONCAT31((uint3)offset_value._4_3_ >> 8,(char)Conf.TempSensor3);
  set_temperature_offset_value(which_i2c,which_chain,offset_value);
  return;
}

