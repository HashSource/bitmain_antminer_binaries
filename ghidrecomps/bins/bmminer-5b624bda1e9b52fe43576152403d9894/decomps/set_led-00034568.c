
/* WARNING: Unknown calling convention */

void set_led(_Bool stop)

{
  char cmd [100];
  
  set_led::blink = !set_led::blink;
  if (isC5_CtrlBoard) {
    if (stop) {
      sprintf(cmd,"echo %d > %s",0,"/sys/class/leds/hps_led0/brightness");
      system(cmd);
      sprintf(cmd,"echo %d > %s",(uint)set_led::blink,"/sys/class/leds/hps_led2/brightness");
      system(cmd);
    }
    else {
      sprintf(cmd,"echo %d > %s",0,"/sys/class/leds/hps_led2/brightness");
      system(cmd);
      sprintf(cmd,"echo %d > %s",(uint)set_led::blink,"/sys/class/leds/hps_led0/brightness");
      system(cmd);
    }
  }
  else if (stop) {
    sprintf(cmd,"echo %d > %s",0,"/sys/class/gpio/gpio38/value");
    system(cmd);
    sprintf(cmd,"echo %d > %s",(uint)set_led::blink,"/sys/class/gpio/gpio37/value");
    system(cmd);
  }
  else {
    sprintf(cmd,"echo %d > %s",0,"/sys/class/gpio/gpio37/value");
    system(cmd);
    sprintf(cmd,"echo %d > %s",(uint)set_led::blink,"/sys/class/gpio/gpio38/value");
    system(cmd);
  }
  return;
}

