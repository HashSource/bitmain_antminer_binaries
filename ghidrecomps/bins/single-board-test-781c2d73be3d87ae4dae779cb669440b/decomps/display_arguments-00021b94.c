
/* WARNING: Unknown calling convention */

void display_arguments(void)

{
  char output [4] [16];
  
  memset(output,0,0x40);
  lseek(lcd_fd,0,0);
  memset(output,0x20,0x40);
  memcpy(output,&Conf,gName_len);
  sprintf(output[1],"IC:%2d P:%2d",Conf.AsicNum,Conf.pattern_number);
  sprintf(output[2],"FREQ: %d",Conf.Freq1);
  sprintf(output[3],"Voltage: %d",Conf.Voltage1);
  write(lcd_fd,output,0x40);
  return;
}

