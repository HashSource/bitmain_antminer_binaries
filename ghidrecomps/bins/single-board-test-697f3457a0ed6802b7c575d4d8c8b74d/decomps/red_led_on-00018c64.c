
/* WARNING: Unknown calling convention */

void red_led_on(void)

{
  write(red_led_fd,&DAT_00035004,1);
  return;
}

