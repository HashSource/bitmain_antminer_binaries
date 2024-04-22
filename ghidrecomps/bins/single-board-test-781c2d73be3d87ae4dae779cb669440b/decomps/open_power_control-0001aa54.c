
/* WARNING: Unknown calling convention */

int open_power_control(void)

{
  power_check_type();
  power_control_fd = open("/sys/class/gpio/gpio907/value",0x801);
  if (-1 < power_control_fd) {
    return power_control_fd;
  }
  puts("open power control gpio failed!!!");
  return power_control_fd;
}

