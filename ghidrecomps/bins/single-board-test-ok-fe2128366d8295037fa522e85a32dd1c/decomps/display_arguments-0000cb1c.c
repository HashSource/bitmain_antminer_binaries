
void display_arguments(void)

{
  undefined auStack_48 [16];
  char acStack_38 [16];
  char acStack_28 [16];
  char acStack_18 [16];
  
  memset(auStack_48,0,0x40);
  lseek(lcd_fd,0,0);
  memset(auStack_48,0x20,0x40);
  memcpy(auStack_48,Conf,gName_len);
  sprintf(acStack_38,"IC:%2d P:%2d",Conf._108_4_,Conf._64_4_);
  sprintf(acStack_28,"FREQ: %d",Conf._72_4_);
  sprintf(acStack_18,"Voltage: %d",Conf._156_4_);
  write(lcd_fd,auStack_48,0x40);
  return;
}

