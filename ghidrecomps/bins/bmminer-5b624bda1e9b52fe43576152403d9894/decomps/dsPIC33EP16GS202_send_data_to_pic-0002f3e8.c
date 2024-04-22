
/* WARNING: Unknown calling convention */

int dsPIC33EP16GS202_send_data_to_pic(uchar which_iic,uchar *buf)

{
  byte *pbVar1;
  byte bVar2;
  byte bVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  char logstr [256];
  
  iVar6 = 0;
  uVar4 = 0x16;
  do {
    pbVar1 = buf + iVar6;
    iVar6 = iVar6 + 1;
    uVar5 = uVar4 + *pbVar1;
    uVar4 = uVar5 & 0xffff;
  } while (iVar6 != 0x10);
  iVar6 = 3;
  while( true ) {
    T9_plus_write_pic_iic(false,false,'\0',which_iic,'U');
    T9_plus_write_pic_iic(false,false,'\0',which_iic,0xaa);
    T9_plus_write_pic_iic(false,false,'\0',which_iic,'\x14');
    T9_plus_write_pic_iic(false,false,'\0',which_iic,'\x02');
    T9_plus_write_pic_iic(false,false,'\0',which_iic,*buf);
    T9_plus_write_pic_iic(false,false,'\0',which_iic,buf[1]);
    T9_plus_write_pic_iic(false,false,'\0',which_iic,buf[2]);
    T9_plus_write_pic_iic(false,false,'\0',which_iic,buf[3]);
    T9_plus_write_pic_iic(false,false,'\0',which_iic,buf[4]);
    T9_plus_write_pic_iic(false,false,'\0',which_iic,buf[5]);
    T9_plus_write_pic_iic(false,false,'\0',which_iic,buf[6]);
    T9_plus_write_pic_iic(false,false,'\0',which_iic,buf[7]);
    T9_plus_write_pic_iic(false,false,'\0',which_iic,buf[8]);
    T9_plus_write_pic_iic(false,false,'\0',which_iic,buf[9]);
    T9_plus_write_pic_iic(false,false,'\0',which_iic,buf[10]);
    T9_plus_write_pic_iic(false,false,'\0',which_iic,buf[0xb]);
    T9_plus_write_pic_iic(false,false,'\0',which_iic,buf[0xc]);
    T9_plus_write_pic_iic(false,false,'\0',which_iic,buf[0xd]);
    T9_plus_write_pic_iic(false,false,'\0',which_iic,buf[0xe]);
    T9_plus_write_pic_iic(false,false,'\0',which_iic,buf[0xf]);
    T9_plus_write_pic_iic(false,false,'\0',which_iic,(uchar)(uVar4 >> 8));
    T9_plus_write_pic_iic(false,false,'\0',which_iic,(uchar)uVar5);
    usleep(200000);
    bVar2 = T9_plus_write_pic_iic(true,false,'\0',which_iic,'\0');
    bVar3 = T9_plus_write_pic_iic(true,false,'\0',which_iic,'\0');
    printf(DAT_0002f638,DAT_0002f634,(uint)bVar2,(uint)bVar3);
    usleep(100000);
    if ((bVar2 == 2) && (bVar3 == 1)) break;
    sprintf(logstr,DAT_0002f63c,DAT_0002f634,(uint)which_iic);
    writeInitLogFile(logstr);
    sleep(1);
    iVar6 = iVar6 + -1;
    if (iVar6 == 0) {
      return 0;
    }
  }
  printf(DAT_0002f640,DAT_0002f634);
  return 1;
}

