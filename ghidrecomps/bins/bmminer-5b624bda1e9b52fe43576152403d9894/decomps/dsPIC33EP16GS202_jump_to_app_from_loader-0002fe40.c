
/* WARNING: Unknown calling convention */

int dsPIC33EP16GS202_jump_to_app_from_loader(uchar which_iic)

{
  byte bVar1;
  byte bVar2;
  int iVar3;
  char logstr [256];
  
  iVar3 = 3;
  printf(DAT_0002ff40,DAT_0002ff3c);
  printf(DAT_0002ff44,DAT_0002ff3c,0,10);
  while( true ) {
    T9_plus_write_pic_iic(false,false,'\0',which_iic,'U');
    T9_plus_write_pic_iic(false,false,'\0',which_iic,0xaa);
    T9_plus_write_pic_iic(false,false,'\0',which_iic,'\x04');
    T9_plus_write_pic_iic(false,false,'\0',which_iic,'\x06');
    T9_plus_write_pic_iic(false,false,'\0',which_iic,'\0');
    T9_plus_write_pic_iic(false,false,'\0',which_iic,'\n');
    usleep(100000);
    bVar1 = T9_plus_write_pic_iic(true,false,'\0',which_iic,'\0');
    bVar2 = T9_plus_write_pic_iic(true,false,'\0',which_iic,'\0');
    printf(DAT_0002ff48,DAT_0002ff3c,(uint)bVar1,(uint)bVar2);
    if ((bVar1 == 6) && (bVar2 == 1)) break;
    sprintf(logstr,DAT_0002ff4c,DAT_0002ff3c,(uint)which_iic);
    writeInitLogFile(logstr);
    sleep(1);
    iVar3 = iVar3 + -1;
    if (iVar3 == 0) {
      return 0;
    }
  }
  sleep(1);
  printf(DAT_0002ff50,DAT_0002ff3c);
  return 1;
}

