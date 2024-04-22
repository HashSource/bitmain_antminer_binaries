
/* WARNING: Unknown calling convention */

int open_red_led(void)

{
  red_led_fd = open("/sys/class/gpio/gpio941/value",0x801);
  if (-1 < red_led_fd) {
    return red_led_fd;
  }
  puts("open red led failed!!!");
  return red_led_fd;
}

