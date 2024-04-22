
/* WARNING: Unknown calling convention */

void set_voltage_setting_time(uchar chain,uchar *time)

{
  int64_t in_stack_00000000;
  
  send_pic_command(chain);
  send_data_to_pic_iic(chain,'\x11',time,'\x06');
  cgsleep_us(in_stack_00000000);
  return;
}

