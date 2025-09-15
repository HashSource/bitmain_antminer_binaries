
bool dsPIC33EP16GS202_pic_heart_beat(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  
  T9_plus_write_pic_iic(0,0,0,param_1,0x55);
  T9_plus_write_pic_iic(0,0,0,param_1,0xaa);
  T9_plus_write_pic_iic(0,0,0,param_1,4);
  T9_plus_write_pic_iic(0,0,0,param_1,0x16);
  T9_plus_write_pic_iic(0,0,0,param_1,0);
  T9_plus_write_pic_iic(0,0,0,param_1,0x1a);
  usleep(500000);
  T9_plus_write_pic_iic(1,0,0,param_1,0);
  iVar1 = T9_plus_write_pic_iic(1,0,0,param_1,0);
  iVar2 = T9_plus_write_pic_iic(1,0,0,param_1,0);
  T9_plus_write_pic_iic(1,0,0,param_1,0);
  T9_plus_write_pic_iic(1,0,0,param_1,0);
  T9_plus_write_pic_iic(1,0,0,param_1,0);
  if (iVar1 != 0x16 || iVar2 != 1) {
    sleep(1);
  }
  return iVar1 == 0x16 && iVar2 == 1;
}

