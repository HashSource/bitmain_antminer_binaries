
undefined4 dsPIC33EP16GS202_erase_pic_app_program_part_1(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  FILE *__stream;
  int iVar3;
  
  iVar3 = 3;
  do {
    T9_plus_write_pic_iic(0,0,0,param_1,0x55);
    T9_plus_write_pic_iic(0,0,0,param_1,0xaa);
    T9_plus_write_pic_iic(0,0,0,param_1,4);
    T9_plus_write_pic_iic(0,0,0,param_1,9);
    T9_plus_write_pic_iic(0,0,0,param_1,0);
    T9_plus_write_pic_iic(0,0,0,param_1,0xd);
    usleep(100000);
    iVar1 = T9_plus_write_pic_iic(1,0,0,param_1,0);
    iVar2 = T9_plus_write_pic_iic(1,0,0,param_1,0);
    usleep(200000);
    if (iVar1 == 9 && iVar2 == 1) {
      return 1;
    }
    if (3 < log_level) {
      __stream = fopen(log_file,(char *)&DAT_0005e760);
      if (__stream != (FILE *)0x0) {
        fprintf(__stream,"%s:%d:%s: %s failed on Chain[%d]!\n","dsPIC33EP16GS202.c",0x101,
                DAT_0003f670,DAT_0003f670,param_1);
      }
      fclose(__stream);
    }
    sleep(1);
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  return 0;
}

