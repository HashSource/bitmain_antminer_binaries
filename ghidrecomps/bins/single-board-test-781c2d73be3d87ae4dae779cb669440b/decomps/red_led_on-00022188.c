
/* WARNING: Unknown calling convention */

void red_led_on(void)

{
  (*(code *)PTR_write_00030190)(red_led_fd,&DAT_0002cbdc,1);
  return;
}

