
/* WARNING: Unknown calling convention */

int dsPIC33EP16GS202_pic_heart_beat(uchar which_iic)

{
  uchar uVar1;
  uchar uVar2;
  int iVar3;
  
  iVar3 = 3;
  while( true ) {
    T9_plus_write_pic_iic(false,false,'\0',which_iic,'U');
    T9_plus_write_pic_iic(false,false,'\0',which_iic,0xaa);
    T9_plus_write_pic_iic(false,false,'\0',which_iic,'\x04');
    T9_plus_write_pic_iic(false,false,'\0',which_iic,'\x16');
    T9_plus_write_pic_iic(false,false,'\0',which_iic,'\0');
    T9_plus_write_pic_iic(false,false,'\0',which_iic,'\x1a');
    usleep(500000);
    T9_plus_write_pic_iic(true,false,'\0',which_iic,'\0');
    uVar1 = T9_plus_write_pic_iic(true,false,'\0',which_iic,'\0');
    uVar2 = T9_plus_write_pic_iic(true,false,'\0',which_iic,'\0');
    T9_plus_write_pic_iic(true,false,'\0',which_iic,'\0');
    T9_plus_write_pic_iic(true,false,'\0',which_iic,'\0');
    T9_plus_write_pic_iic(true,false,'\0',which_iic,'\0');
    if ((uVar1 == '\x16') && (uVar2 == '\x01')) break;
    sleep(1);
    iVar3 = iVar3 + -1;
    if (iVar3 == 0) {
      return 0;
    }
  }
  return 1;
}

