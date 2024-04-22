
/* WARNING: Unknown calling convention */

int dsPIC33EP16GS202_reset_pic(uchar which_iic)

{
  byte bVar1;
  byte bVar2;
  int iVar3;
  char logstr [256];
  
  iVar3 = 3;
  printf(DAT_0002fc80,DAT_0002fc7c);
  printf(DAT_0002fc84,DAT_0002fc7c,(uint)which_iic,0,0xb);
  while( true ) {
    T9_plus_write_pic_iic(false,false,'\0',which_iic,'U');
    T9_plus_write_pic_iic(false,false,'\0',which_iic,0xaa);
    T9_plus_write_pic_iic(false,false,'\0',which_iic,'\x04');
    T9_plus_write_pic_iic(false,false,'\0',which_iic,'\a');
    T9_plus_write_pic_iic(false,false,'\0',which_iic,'\0');
    T9_plus_write_pic_iic(false,false,'\0',which_iic,'\v');
    usleep(400000);
    bVar1 = T9_plus_write_pic_iic(true,false,'\0',which_iic,'\0');
    bVar2 = T9_plus_write_pic_iic(true,false,'\0',which_iic,'\0');
    printf(DAT_0002fc88,DAT_0002fc7c,(uint)bVar1,(uint)bVar2);
    usleep(100000);
    if ((bVar1 == 7) && (bVar2 == 1)) break;
    sprintf(logstr,DAT_0002fc8c);
    writeInitLogFile(logstr);
    sleep(1);
    iVar3 = iVar3 + -1;
    if (iVar3 == 0) {
      return 0;
    }
  }
  printf(DAT_0002fc90,DAT_0002fc7c,DAT_0002fc7c,(uint)which_iic);
  sleep(1);
  return 1;
}

