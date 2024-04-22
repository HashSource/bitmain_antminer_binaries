
void led_on(char *led)

{
  char *led_local;
  char cmd [64];
  
  memset(cmd,0,0x40);
  sprintf(cmd,"echo %d > %s",1,led);
  system(cmd);
  return;
}

