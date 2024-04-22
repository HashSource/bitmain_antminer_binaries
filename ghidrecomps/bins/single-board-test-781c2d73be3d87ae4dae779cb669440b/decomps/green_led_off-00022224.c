
/* WARNING: Unknown calling convention */

void green_led_off(void)

{
  (*(code *)PTR_write_00030190)(green_led_fd,&DAT_0002cbd8,1);
  return;
}

