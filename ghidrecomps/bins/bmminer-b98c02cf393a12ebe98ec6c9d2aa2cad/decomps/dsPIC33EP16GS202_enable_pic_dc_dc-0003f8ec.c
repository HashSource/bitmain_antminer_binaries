
undefined4 dsPIC33EP16GS202_enable_pic_dc_dc(undefined4 param_1,int param_2)

{
  int iVar1;
  int iVar2;
  FILE *__stream;
  int iVar3;
  
  iVar3 = 3;
  do {
    T9_plus_write_pic_iic(0,0,0,param_1,0x55);
    T9_plus_write_pic_iic(0,0,0,param_1,0xaa);
    T9_plus_write_pic_iic(0,0,0,param_1,5);
    T9_plus_write_pic_iic(0,0,0,param_1,0x15);
    T9_plus_write_pic_iic(0,0,0,param_1,param_2);
    T9_plus_write_pic_iic(0,0,0,param_1,(param_2 + 0x1aU) * 0x10000 >> 0x18);
    T9_plus_write_pic_iic(0,0,0,param_1,param_2 + 0x1aU & 0xff);
    usleep(10000);
    iVar1 = T9_plus_write_pic_iic(1,0,0,param_1,0);
    iVar2 = T9_plus_write_pic_iic(1,0,0,param_1,0);
    if (iVar1 == 0x15 && iVar2 == 1) {
      return 1;
    }
    if (3 < log_level) {
      __stream = fopen(log_file,(char *)&DAT_0005e760);
      if (__stream != (FILE *)0x0) {
        fprintf(__stream,"%s:%d:%s: %s failed on Chain[%d]!\n","dsPIC33EP16GS202.c",0xd6,
                DAT_0003fa14,DAT_0003fa14,param_1);
      }
      fclose(__stream);
    }
    sleep(1);
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  return 0;
}

