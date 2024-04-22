
/* WARNING: Unknown calling convention */

int get_fixed_total_hash_rate(void)

{
  int iVar1;
  int total_rate;
  int fixed_total_rate;
  
  iVar1 = get_eeprom_total_hash_rate();
  if (opt_bitmain_economic_mode == false) {
    fixed_total_rate = (iVar1 / 1000) * 1000;
  }
  else {
    fixed_total_rate = (iVar1 / 500) * 500;
  }
  return fixed_total_rate;
}

