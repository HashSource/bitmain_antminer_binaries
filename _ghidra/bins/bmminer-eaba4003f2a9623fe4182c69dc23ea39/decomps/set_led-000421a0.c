
void set_led(_Bool stop)

{
  _Bool stop_local;
  char cmd [100];
  
  set_led::blink = !set_led::blink;
  if (stop) {
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

