
void write_host_MAC_and_time(uchar chain,uchar *buf)

{
  uchar *buf_local;
  uchar chain_local;
  
  send_pic_command(chain);
  send_data_to_pic_iic(chain,'\x14',buf,'\f');
  cgsleep_us(100000);
  return;
}

