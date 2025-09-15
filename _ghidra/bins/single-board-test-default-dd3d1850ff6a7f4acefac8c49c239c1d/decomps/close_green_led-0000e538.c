
void close_green_led(void)

{
  close(green_led_fd);
  puts("green led closed!!!");
  return;
}

