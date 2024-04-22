
/* WARNING: Unknown calling convention */

void red_led_off(void)

{
  (*(code *)PTR_write_00030190)(red_led_fd,&DAT_0002cbd8,1);
  return;
}

