
void led_blink(char *led)

{
  char *led_local;
  char cmd [64];
  
  memset(cmd,0,0x40);
  led_blink::is_on = led_blink::is_on == false;
  sprintf(cmd,"echo %d > %s",(uint)!led_blink::is_on,led);
  system(cmd);
  return;
}

