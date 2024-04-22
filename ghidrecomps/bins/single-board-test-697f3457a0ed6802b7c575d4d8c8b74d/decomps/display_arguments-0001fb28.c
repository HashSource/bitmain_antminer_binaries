
/* WARNING: Unknown calling convention */

void display_arguments(void)

{
  size_t __n;
  char *__src;
  char output [4] [16];
  
  memset(output,0,0x40);
  lseek(cgpu.lcd_fd,0,0);
  memset(output,0x20,0x40);
  __src = app_conf->name;
  __n = strlen(app_conf->name);
  memcpy(output,__src,__n);
  sprintf(output[1],"IC:%2d",app_conf->asic_num);
  sprintf(output[2],"FREQ: %d",app_conf->pcba_freq);
  sprintf(output[3],"Voltage: %d",app_conf->pcba_voltage);
  write(cgpu.lcd_fd,output,0x40);
  return;
}

