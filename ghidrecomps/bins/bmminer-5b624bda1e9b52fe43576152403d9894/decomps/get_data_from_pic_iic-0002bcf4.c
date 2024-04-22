
/* WARNING: Unknown calling convention */

void get_data_from_pic_iic(uchar chain,uchar command,uchar *buf,uchar length)

{
  uchar uVar1;
  int iVar2;
  
  write_pic_iic(false,false,'\0',chain,command);
  if (length != 0) {
    iVar2 = 0;
    do {
      uVar1 = write_pic_iic(true,false,'\0',chain,'\0');
      buf[iVar2] = uVar1;
      iVar2 = iVar2 + 1;
    } while (iVar2 < (int)(uint)length);
  }
  return;
}

