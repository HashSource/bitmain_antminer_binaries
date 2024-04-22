
/* WARNING: Unknown calling convention */

void send_data_to_pic_iic(uchar chain,uchar command,uchar *buf,uchar length)

{
  uchar *puVar1;
  int iVar2;
  
  write_pic_iic(false,false,'\0',chain,command);
  if (length != 0) {
    iVar2 = 0;
    do {
      puVar1 = buf + iVar2;
      iVar2 = iVar2 + 1;
      write_pic_iic(false,false,'\0',chain,*puVar1);
    } while (iVar2 < (int)(uint)length);
  }
  return;
}

