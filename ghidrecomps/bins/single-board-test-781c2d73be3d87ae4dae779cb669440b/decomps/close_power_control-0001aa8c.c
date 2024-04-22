
/* WARNING: Unknown calling convention */

void close_power_control(void)

{
  undefined4 extraout_r1;
  undefined4 in_r2;
  undefined4 in_r3;
  
  close(power_control_fd);
  (*(code *)PTR_puts_0003015c)("power control gpio closed!!!",extraout_r1,in_r2,in_r3);
  return;
}

