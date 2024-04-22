
/* WARNING: Unknown calling convention */

void adjust_voltage(uchar which_chain,uchar which_iic)

{
  byte N;
  byte bVar1;
  uint uVar2;
  
  uVar2 = get_target_voltage();
  N = power_calculate_voltage(uVar2);
  bVar1 = power_calculate_voltage(Conf.pre_open_core_voltage);
  uVar2 = (uint)bVar1;
  printf("\n--- %s: target_N = %d, origin_N = %d\n",DAT_0001b474,(uint)N,uVar2);
  for (; uVar2 = uVar2 + 0x14, uVar2 < N; uVar2 = uVar2 & 0xff) {
    power_set_voltage((uchar)uVar2);
    usleep(1000000);
  }
  power_set_voltage(N);
  usleep(1000000);
  (*(code *)PTR_printf_00030118)("\n--- %s: done\n",DAT_0001b474);
  return;
}

