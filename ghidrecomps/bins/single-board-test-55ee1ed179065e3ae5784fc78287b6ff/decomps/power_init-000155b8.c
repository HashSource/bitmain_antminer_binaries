
void power_init(void)

{
  puts("power init ... ");
  power_check_protocal_type();
  power_on();
  return;
}

