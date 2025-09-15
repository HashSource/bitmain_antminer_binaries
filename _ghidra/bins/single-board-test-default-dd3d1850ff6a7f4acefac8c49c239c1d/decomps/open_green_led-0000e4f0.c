
int open_green_led(void)

{
  green_led_fd = open("/sys/class/gpio/gpio942/value",0x801);
  if (green_led_fd < 0) {
    puts("open green led failed!!!");
  }
  return green_led_fd;
}

