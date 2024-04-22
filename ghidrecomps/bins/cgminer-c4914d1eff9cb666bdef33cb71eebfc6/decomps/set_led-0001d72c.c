
/* WARNING: Unknown calling convention */

void set_led(void)

{
  STATUS_CODE SVar1;
  STATUS_CODE stopcode;
  
  SVar1 = get_error_type();
  switch(SVar1) {
  case STATUS_OK:
    led_off("/sys/class/gpio/gpio941/value");
    led_blink("/sys/class/gpio/gpio942/value");
    break;
  case ERROR_OVER_MAXTEMP:
    led_blink("/sys/class/gpio/gpio941/value");
    led_off("/sys/class/gpio/gpio942/value");
    break;
  case ERROR_FAN_LOST:
    led_off("/sys/class/gpio/gpio941/value");
    led_off("/sys/class/gpio/gpio942/value");
    break;
  case ERROR_NETWORK_LOST:
    led_off("/sys/class/gpio/gpio941/value");
    led_on("/sys/class/gpio/gpio942/value");
    break;
  case ERROR_UNKOWN_STATUS:
    led_blink("/sys/class/gpio/gpio941/value");
    led_off("/sys/class/gpio/gpio942/value");
  }
  return;
}

