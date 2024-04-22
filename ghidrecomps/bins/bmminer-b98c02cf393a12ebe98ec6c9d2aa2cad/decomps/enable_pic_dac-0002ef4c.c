
void enable_pic_dac(undefined4 param_1)

{
  FILE *__stream;
  char acStack_74 [100];
  
  if (is7007_ctrl_board == -1) {
    isC5_Board();
  }
  if (is7007_ctrl_board == 1) {
    sprintf(acStack_74,"echo %d > %s",0,"/sys/class/gpio/gpio907/value");
    if (log_level < 4) goto LAB_0002ef8e;
    __stream = fopen(log_file,(char *)&DAT_0005e760);
    if (__stream != (FILE *)0x0) {
      fprintf(__stream,"%s:%d:%s: %s\n","driver-btm-c5.c",0xaf9,DAT_0002f050,acStack_74);
    }
  }
  else {
    sprintf(acStack_74,"echo %d > %s",0,"/sys/class/gpio/gpio36/value");
    if (log_level < 4) goto LAB_0002ef8e;
    __stream = fopen(log_file,(char *)&DAT_0005e760);
    if (__stream != (FILE *)0x0) {
      fprintf(__stream,"%s:%d:%s: %s\n","driver-btm-c5.c",0xb00,DAT_0002f050,acStack_74);
    }
  }
  fclose(__stream);
LAB_0002ef8e:
  system(acStack_74);
  dsPIC33EP16GS202_enable_pic_dc_dc(param_1,1);
  return;
}

