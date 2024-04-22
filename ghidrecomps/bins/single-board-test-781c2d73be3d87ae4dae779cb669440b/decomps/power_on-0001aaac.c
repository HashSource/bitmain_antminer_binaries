
/* WARNING: Unknown calling convention */

void power_on(void)

{
  (*(code *)PTR_write_00030190)(power_control_fd,&DAT_0002cbd8,1);
  return;
}

