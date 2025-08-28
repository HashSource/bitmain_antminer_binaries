
void set_voltage_setting_time(uchar chain,uchar *time)

{
  uchar *time_local;
  uchar chain_local;
  
  send_pic_command(chain);
  send_data_to_pic_iic(chain,'\x11',time,'\x06');
  cgsleep_us(100000);
  return;
}

