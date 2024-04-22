
/* WARNING: Unknown calling convention */

int dsPIC33EP16GS202_enable_pic_dc_dc(uchar which_iic,uchar enable)

{
  uchar uVar1;
  uchar uVar2;
  int iVar3;
  char logstr [256];
  
  iVar3 = 3;
  while( true ) {
    T9_plus_write_pic_iic(false,false,'\0',which_iic,'U');
    T9_plus_write_pic_iic(false,false,'\0',which_iic,0xaa);
    T9_plus_write_pic_iic(false,false,'\0',which_iic,'\x05');
    T9_plus_write_pic_iic(false,false,'\0',which_iic,'\x15');
    T9_plus_write_pic_iic(false,false,'\0',which_iic,enable);
    T9_plus_write_pic_iic(false,false,'\0',which_iic,(uchar)(enable + 0x1a >> 8));
    T9_plus_write_pic_iic(false,false,'\0',which_iic,(uchar)(enable + 0x1a));
    usleep(10000);
    uVar1 = T9_plus_write_pic_iic(true,false,'\0',which_iic,'\0');
    uVar2 = T9_plus_write_pic_iic(true,false,'\0',which_iic,'\0');
    if ((uVar1 == '\x15') && (uVar2 == '\x01')) break;
    sprintf(logstr,DAT_0002f838);
    writeInitLogFile(logstr);
    sleep(1);
    iVar3 = iVar3 + -1;
    if (iVar3 == 0) {
      return 0;
    }
  }
  printf(DAT_0002f840,DAT_0002f83c,DAT_0002f83c,(uint)which_iic);
  return 1;
}

