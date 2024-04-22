
/* WARNING: Unknown calling convention */

void close_green_led(void)

{
  undefined4 extraout_r1;
  undefined4 in_r2;
  undefined4 in_r3;
  
  close(green_led_fd);
  (*(code *)PTR_puts_0003015c)("green led closed!!!",extraout_r1,in_r2,in_r3);
  return;
}

