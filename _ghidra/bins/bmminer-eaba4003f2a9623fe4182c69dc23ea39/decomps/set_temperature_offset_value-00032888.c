
void set_temperature_offset_value(uchar chain,uchar *value)

{
  uchar *value_local;
  uchar chain_local;
  
  send_pic_command(chain);
  send_data_to_pic_iic(chain,'\"',value,'\b');
  cgsleep_ms(100000);
  return;
}

