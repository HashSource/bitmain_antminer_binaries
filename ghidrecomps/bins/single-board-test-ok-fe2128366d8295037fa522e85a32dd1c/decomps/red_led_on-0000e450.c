
void red_led_on(void)

{
  write(red_led_fd,&DAT_0001abd4,1);
  return;
}

