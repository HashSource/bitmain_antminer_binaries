
/* WARNING: Unknown calling convention */

int get_fixed_total_hash_rate(void)

{
  int iVar1;
  int total_rate;
  
  iVar1 = get_eeprom_total_hash_rate();
  iVar1 = fix_hash_rate(iVar1);
  return iVar1;
}

