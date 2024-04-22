
/* WARNING: Unknown calling convention */

void red_led_off(void)

{
  write(red_led_fd,&DAT_00035008,1);
  return;
}

