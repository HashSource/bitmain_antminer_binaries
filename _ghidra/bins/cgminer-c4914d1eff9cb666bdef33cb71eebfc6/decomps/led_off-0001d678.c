
void led_off(char *led)

{
  char *led_local;
  char cmd [64];
  
  memset(cmd,0,0x40);
  sprintf(cmd,"echo %d > %s",0,led);
  system(cmd);
  return;
}

