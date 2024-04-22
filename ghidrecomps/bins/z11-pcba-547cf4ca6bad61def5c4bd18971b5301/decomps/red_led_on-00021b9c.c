
void red_led_on(void)

{
  write(red_led_fd,&DAT_000341c4,1);
  return;
}

