
uchar reset_iic_pic(uchar chain)

{
  uchar extraout_r3;
  uchar chain_local;
  uchar ret;
  
  send_pic_command(chain);
  write_pic_iic(false,false,'\0',chain,'\a');
  cgsleep_us(100000);
  return extraout_r3;
}

