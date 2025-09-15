
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void green_led_on(void)

{
  write(green_led_fd,&DAT_00035004,1);
  return;
}

