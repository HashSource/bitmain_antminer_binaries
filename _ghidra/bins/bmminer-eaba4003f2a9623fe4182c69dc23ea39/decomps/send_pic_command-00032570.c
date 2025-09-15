
void send_pic_command(uchar chain)

{
  uchar chain_local;
  
  write_pic_iic(false,false,'\0',chain,'U');
  write_pic_iic(false,false,'\0',chain,0xaa);
  return;
}

