
/* WARNING: Unknown calling convention */

void green_led_on(void)

{
  (*(code *)PTR_write_00030190)(green_led_fd,&DAT_0002cbdc,1);
  return;
}

