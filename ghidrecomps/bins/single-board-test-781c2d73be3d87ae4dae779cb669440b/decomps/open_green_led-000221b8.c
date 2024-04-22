
/* WARNING: Unknown calling convention */

int open_green_led(void)

{
  green_led_fd = open("/sys/class/gpio/gpio942/value",0x801);
  if (-1 < green_led_fd) {
    return green_led_fd;
  }
  puts("open green led failed!!!");
  return green_led_fd;
}

