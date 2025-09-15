
undefined4 GetTotalRate(void)

{
  undefined4 uVar1;
  
  if (opt_economic_mode != '\0') {
    uVar1 = GetTotalRate_part_12();
    return uVar1;
  }
  return ideal_total_hash_rate;
}

