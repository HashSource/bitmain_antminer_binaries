
void send_data_to_pic_flash(uchar chain,uchar *buf)

{
  uchar *buf_local;
  uchar chain_local;
  
  send_pic_command(chain);
  send_data_to_pic_iic(chain,'\x02',buf,'\x10');
  return;
}

