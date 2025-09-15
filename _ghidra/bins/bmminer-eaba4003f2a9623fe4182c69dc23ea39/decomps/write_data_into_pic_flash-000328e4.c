
uchar write_data_into_pic_flash(uchar chain)

{
  uchar chain_local;
  
  send_pic_command(chain);
  write_pic_iic(false,false,'\0',chain,'\x05');
  usleep(100000);
  return '\0';
}

