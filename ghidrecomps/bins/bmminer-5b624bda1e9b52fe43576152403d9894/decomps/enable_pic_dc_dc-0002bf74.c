
/* WARNING: Unknown calling convention */

void enable_pic_dc_dc(uchar chain)

{
  send_pic_command(chain);
  write_pic_iic(false,false,'\0',chain,'\x15');
  write_pic_iic(false,false,'\0',chain,'\x01');
  return;
}

