
uchar jump_to_app_from_loader(uchar chain)

{
  uchar extraout_r3;
  uchar chain_local;
  uchar ret;
  
  send_pic_command(chain);
  write_pic_iic(false,false,'\0',chain,'\x06');
  cgsleep_us(100000);
  return extraout_r3;
}

