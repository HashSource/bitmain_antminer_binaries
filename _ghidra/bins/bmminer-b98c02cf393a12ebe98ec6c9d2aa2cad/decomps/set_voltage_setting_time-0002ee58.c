
void set_voltage_setting_time(undefined4 param_1,undefined4 param_2)

{
  send_pic_command();
  send_data_to_pic_iic(param_1,0x11,param_2,6);
  cgsleep_us(100000,0);
  return;
}

