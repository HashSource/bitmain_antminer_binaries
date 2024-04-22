
/* WARNING: Unknown calling convention */

void power_off(void)

{
  (*(code *)PTR_write_00030190)(power_control_fd,&DAT_0002cbdc,1);
  return;
}

