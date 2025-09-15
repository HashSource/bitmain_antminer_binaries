
void get_data_from_pic_flash(uchar chain,uchar *buf)

{
  uchar *buf_local;
  uchar chain_local;
  
  send_pic_command(chain);
  get_data_from_pic_iic(chain,'\x03',buf,'\x10');
  return;
}

