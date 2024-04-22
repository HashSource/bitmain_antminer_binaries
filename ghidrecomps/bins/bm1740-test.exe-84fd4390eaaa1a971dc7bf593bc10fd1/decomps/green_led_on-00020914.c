
void green_led_on(void)

{
  write(green_led_fd,&DAT_0002e694,1);
  return;
}

