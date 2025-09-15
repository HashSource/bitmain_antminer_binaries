
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void red_led_on(void)

{
  write(red_led_fd,&DAT_00035004,1);
  return;
}

