
undefined4 get_pic_software_version(undefined4 param_1,undefined *param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  FILE *__stream;
  int iVar6;
  
  iVar6 = 3;
  *param_2 = 0xff;
  do {
    T9_plus_write_pic_iic(0,0,0,param_1,0x55);
    T9_plus_write_pic_iic(0,0,0,param_1,0xaa);
    T9_plus_write_pic_iic(0,0,0,param_1,4);
    T9_plus_write_pic_iic(0,0,0,param_1,0x17);
    T9_plus_write_pic_iic(0,0,0,param_1,0);
    T9_plus_write_pic_iic(0,0,0,param_1,0x1b);
    usleep(100000);
    iVar1 = T9_plus_write_pic_iic(1,0,0,param_1,0);
    iVar2 = T9_plus_write_pic_iic(1,0,0,param_1,0);
    iVar3 = T9_plus_write_pic_iic(1,0,0,param_1,0);
    uVar4 = T9_plus_write_pic_iic(1,0,0,param_1,0);
    uVar5 = T9_plus_write_pic_iic(1,0,0,param_1,0);
    usleep(100000);
    if (iVar2 == 0x17 && iVar1 == 5) {
      if ((uVar4 == (iVar3 + 0x1cU & 0xffff) >> 8) && (uVar5 == (iVar3 + 0x1cU & 0xff))) {
        *param_2 = (char)iVar3;
        return 1;
      }
    }
    else if (3 < log_level) {
      __stream = fopen(log_file,(char *)&DAT_0005e760);
      if (__stream != (FILE *)0x0) {
        fprintf(__stream,"%s:%d:%s: %s failed on Chain[%d]!\n","dsPIC33EP16GS202.c",0x3d,
                DAT_0003f7d8,DAT_0003f7d8,param_1);
      }
      fclose(__stream);
    }
    sleep(1);
    iVar6 = iVar6 + -1;
    if (iVar6 == 0) {
      return 0;
    }
  } while( true );
}

