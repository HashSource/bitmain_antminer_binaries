
void set_iic_power_to_working_voltage_part_2(void)

{
  undefined4 uVar1;
  undefined4 extraout_s1;
  
  uVar1 = get_avg_voltage();
  if ((int)((uint)((double)CONCAT44(extraout_s1,uVar1) < 9.7) << 0x1f) < 0) {
    stop_mining("power voltage too low\n");
  }
  return;
}

