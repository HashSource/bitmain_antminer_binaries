
void red_led_on(void)

{
  write(red_led_fd,&DAT_00034678,1);
  return;
}

