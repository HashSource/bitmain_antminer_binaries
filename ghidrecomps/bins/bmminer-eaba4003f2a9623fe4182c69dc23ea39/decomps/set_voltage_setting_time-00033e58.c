
/* WARNING: Variable defined which should be unmapped: time-local */

void set_voltage_setting_time(uchar chain,uchar *time)

{
  uchar *time_local;
  undefined3 uStack_c;
  uchar chain_local;
  
  _uStack_c = CONCAT13(chain,uStack_c);
  send_pic_command(chain);
  send_data_to_pic_iic(chain,'\x11',time,'\x06');
  cgsleep_us(CONCAT44(_uStack_c,time));
  return;
}

