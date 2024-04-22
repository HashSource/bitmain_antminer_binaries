
/* WARNING: Unknown calling convention */

void green_led_on(void)

{
  write(green_led_fd,&DAT_00035004,1);
  return;
}

