
int getHighestVoltage(void)

{
  int local_10;
  int local_c;
  
  local_10 = 0;
  for (local_c = 0; local_c < 0x10; local_c = local_c + 1) {
    if ((*(int *)(cgpu + (local_c + 0x9c638) * 4) != 0) &&
       (local_10 < *(int *)(chain_vol_value + local_c * 4))) {
      local_10 = *(int *)(chain_vol_value + local_c * 4);
    }
  }
  return local_10;
}

