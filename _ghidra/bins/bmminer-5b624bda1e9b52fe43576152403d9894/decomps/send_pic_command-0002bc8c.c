
/* WARNING: Unknown calling convention */

void send_pic_command(uchar chain)

{
  write_pic_iic(false,false,'\0',chain,'U');
  write_pic_iic(false,false,'\0',chain,0xaa);
  return;
}

