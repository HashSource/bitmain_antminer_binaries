
void green_led_on(void)

{
  write(green_led_fd,&DAT_000341c4,1);
  return;
}

