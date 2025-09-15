
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void green_led_off(void)

{
  write(green_led_fd,&DAT_00035008,1);
  return;
}

