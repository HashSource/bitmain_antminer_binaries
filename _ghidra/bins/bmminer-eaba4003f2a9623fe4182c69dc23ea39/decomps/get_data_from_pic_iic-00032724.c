
void get_data_from_pic_iic(uchar chain,uchar command,uchar *buf,uchar length)

{
  uchar uVar1;
  uchar *buf_local;
  uchar length_local;
  uchar command_local;
  uchar chain_local;
  int i;
  
  write_pic_iic(false,false,'\0',chain,command);
  for (i = 0; i < (int)(uint)length; i = i + 1) {
    uVar1 = write_pic_iic(true,false,'\0',chain,'\0');
    buf[i] = uVar1;
  }
  return;
}

