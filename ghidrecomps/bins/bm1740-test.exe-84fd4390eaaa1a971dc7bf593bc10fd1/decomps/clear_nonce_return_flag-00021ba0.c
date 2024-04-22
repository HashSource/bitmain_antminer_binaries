
void clear_nonce_return_flag(void)

{
  bool bVar1;
  int iVar2;
  uint local_3c;
  uint local_38;
  uint local_34;
  uint local_30;
  uint local_2c;
  uint local_28;
  uint local_24;
  uint local_1c;
  uint local_18;
  int local_14;
  int local_10;
  int local_c;
  
  local_14 = 0;
  local_18 = 0;
  local_1c = 0;
  local_30 = Conf._204_4_;
  local_34 = Conf._208_4_;
  local_38 = Conf._212_4_;
  local_3c = Conf._216_4_;
  puts("clear_nonce_return_flag");
  if (Conf._108_4_ == 1) {
    for (local_10 = 0; local_10 < 0x20; local_10 = local_10 + 1) {
      if ((local_30 & 1) != 0) {
        local_14 = local_14 + 1;
      }
      local_30 = local_30 >> 1;
      if ((local_34 & 1) != 0) {
        local_14 = local_14 + 1;
      }
      local_34 = local_34 >> 1;
      if ((local_38 & 1) != 0) {
        local_14 = local_14 + 1;
      }
      local_38 = local_38 >> 1;
      if ((local_3c & 1) != 0) {
        local_14 = local_14 + 1;
      }
      local_3c = local_3c >> 1;
    }
    printf("%s: single ASIC get_pattern_loop = %d\n","clear_nonce_return_flag",local_14);
  }
  if (Conf._116_4_ == 0x569) {
    local_1c = 0x32;
  }
  if (gHashBoard_V9 != '\0') {
    local_18 = 4;
  }
  if (Conf._108_4_ == 1) {
    for (local_c = 0; local_c < local_14; local_c = local_c + 1) {
      for (local_2c = 0; local_2c < (uint)Conf._64_4_; local_2c = local_2c + 1) {
        bVar1 = false;
        while (!bVar1) {
          *(undefined4 *)(*(int *)(cgpu + (local_c + 0x402a) * 4 + 4) + local_2c * 0x38 + 0x34) = 0;
          bVar1 = true;
        }
      }
    }
  }
  else {
    for (local_24 = 0; local_24 < local_18; local_24 = local_24 + 1) {
      iVar2 = *(int *)(cgpu + (local_24 + 0x402a) * 4 + 4);
      for (local_28 = 0; local_28 < local_1c; local_28 = local_28 + 1) {
        for (local_2c = 0; local_2c < (uint)Conf._64_4_; local_2c = local_2c + 1) {
          bVar1 = false;
          while (!bVar1) {
            *(undefined4 *)(iVar2 + (local_28 * Conf._64_4_ + local_2c) * 0x38 + 0x34) = 0;
            bVar1 = true;
          }
        }
      }
    }
  }
  return;
}

