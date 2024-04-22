
undefined4 set_Voltage_S9_plus_plus_BM1387_54(undefined4 param_1,int param_2)

{
  int iVar1;
  int iVar2;
  FILE *__stream;
  int iVar3;
  
  if (param_2 << 0x18 < 0) {
    return 0;
  }
  iVar3 = 3;
  do {
    T9_plus_write_pic_iic(0,0,0,param_1,0x55);
    T9_plus_write_pic_iic(0,0,0,param_1,0xaa);
    T9_plus_write_pic_iic(0,0,0,param_1,7);
    T9_plus_write_pic_iic(0,0,0,param_1,0x10);
    T9_plus_write_pic_iic(0,0,0,param_1,param_2);
    T9_plus_write_pic_iic(0,0,0,param_1,0);
    T9_plus_write_pic_iic(0,0,0,param_1,0);
    T9_plus_write_pic_iic(0,0,0,param_1,0);
    T9_plus_write_pic_iic(0,0,0,param_1,param_2 + 0x17U & 0xff);
    usleep(100000);
    iVar1 = T9_plus_write_pic_iic(1,0,0,param_1,0);
    iVar2 = T9_plus_write_pic_iic(1,0,0,param_1,0);
    if (iVar1 == 0x10 && iVar2 == 1) {
      write_EEPROM_iic(0,1,0x90,param_1,param_2);
      return 1;
    }
    if (3 < log_level) {
      __stream = fopen(log_file,(char *)&DAT_0005e760);
      if (__stream != (FILE *)0x0) {
        fprintf(__stream,"%s:%d:%s: %s failed on Chain[%d]!\n\n","driver-btm-c5.c",0x9ee,
                DAT_0002edb8,DAT_0002edb8,param_1);
      }
      fclose(__stream);
    }
    sleep(1);
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  return 0;
}

