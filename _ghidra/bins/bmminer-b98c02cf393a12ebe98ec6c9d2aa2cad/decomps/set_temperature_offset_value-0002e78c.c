
void set_temperature_offset_value(undefined4 param_1,undefined4 param_2)

{
  send_pic_command();
  send_data_to_pic_iic(param_1,0x22,param_2,8);
  cgsleep_ms(100000);
  return;
}

