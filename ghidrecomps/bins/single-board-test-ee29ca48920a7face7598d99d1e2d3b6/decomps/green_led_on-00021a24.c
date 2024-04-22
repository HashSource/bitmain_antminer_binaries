
void green_led_on(void)

{
  write(green_led_fd,&DAT_00034678,1);
  return;
}

