
/* WARNING: Unknown calling convention */

void set_led(void)

{
  STATUS_CODE SVar1;
  char cmd [100];
  STATUS_CODE stopcode;
  
  memset(cmd,0,100);
  set_led::blink = set_led::blink == false;
  SVar1 = get_error_type();
  if (SVar1 == STATUS_OK) {
    sprintf(cmd,"echo %d > %s",0,"/sys/class/gpio/gpio941/value");
    system(cmd);
    sprintf(cmd,"echo %d > %s",(uint)set_led::blink,"/sys/class/gpio/gpio942/value");
    system(cmd);
  }
  else if ((SVar1 != STATUS_INIT) && (SVar1 < 6)) {
    sprintf(cmd,"echo %d > %s",0,"/sys/class/gpio/gpio942/value");
    system(cmd);
    sprintf(cmd,"echo %d > %s",(uint)set_led::blink,"/sys/class/gpio/gpio941/value");
    system(cmd);
  }
  return;
}

