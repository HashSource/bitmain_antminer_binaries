
void red_led_on(void)

{
  write(red_led_fd,&DAT_0002e694,1);
  return;
}

