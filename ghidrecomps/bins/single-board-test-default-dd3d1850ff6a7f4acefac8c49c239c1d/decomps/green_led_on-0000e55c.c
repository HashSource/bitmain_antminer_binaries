
void green_led_on(void)

{
  write(green_led_fd,&DAT_0001adbc,1);
  return;
}

