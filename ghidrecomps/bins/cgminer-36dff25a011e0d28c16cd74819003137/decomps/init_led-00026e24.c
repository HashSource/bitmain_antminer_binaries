
/* WARNING: Unknown calling convention */

void init_led(void)

{
  char cmd [100];
  
  memset(cmd,0,100);
  sprintf(cmd,"echo %d > %s",0,"/sys/class/gpio/gpio942/value");
  system(cmd);
  sprintf(cmd,"echo %d > %s",0,"/sys/class/gpio/gpio941/value");
  system(cmd);
  return;
}

