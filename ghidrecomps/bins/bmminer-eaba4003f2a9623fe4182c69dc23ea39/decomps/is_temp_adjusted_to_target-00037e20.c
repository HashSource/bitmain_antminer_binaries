
/* WARNING: Unknown calling convention */

_Bool is_temp_adjusted_to_target(void)

{
  int iVar1;
  int temp_diff;
  
  temp_highest = dev->temp_top1[1];
  if (target_temp < temp_highest) {
    iVar1 = temp_highest - target_temp;
  }
  else {
    iVar1 = target_temp - temp_highest;
  }
  return iVar1 < 3;
}

