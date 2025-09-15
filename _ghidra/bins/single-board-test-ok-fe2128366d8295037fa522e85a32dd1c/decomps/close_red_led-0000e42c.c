
void close_red_led(void)

{
  close(red_led_fd);
  puts("red led closed!!!");
  return;
}

