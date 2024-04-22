
int open_red_led(void)

{
  red_led_fd = open("/sys/class/gpio/gpio941/value",0x801);
  if (red_led_fd < 0) {
    puts("open red led failed!!!");
  }
  return red_led_fd;
}

