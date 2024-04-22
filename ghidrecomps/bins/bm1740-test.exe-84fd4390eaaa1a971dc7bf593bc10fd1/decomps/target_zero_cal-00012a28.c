
int target_zero_cal(int param_1)

{
  int iVar1;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  
  local_c = 0;
  local_38 = 0;
  local_34 = 0;
  local_30 = 0;
  local_2c = 0;
  local_28 = 0;
  local_24 = 0;
  local_20 = 0;
  local_1c = 0;
  for (local_10 = 0; local_10 < 0x20; local_10 = local_10 + 1) {
    *(undefined *)((int)&local_38 + local_10) = *(undefined *)(param_1 + (0x1f - local_10));
  }
  local_14 = 0;
  do {
    if (0x1f < local_14) {
      return local_c;
    }
    for (local_18 = 7; -1 < local_18; local_18 = local_18 + -1) {
      iVar1 = bit_read((int)&local_38 + local_14,local_18);
      if (iVar1 != 0) {
        return local_c;
      }
      local_c = local_c + 1;
    }
    local_14 = local_14 + 1;
  } while( true );
}

