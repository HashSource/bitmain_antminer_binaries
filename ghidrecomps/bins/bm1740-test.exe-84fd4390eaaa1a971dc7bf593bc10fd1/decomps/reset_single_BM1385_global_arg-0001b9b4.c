
void reset_single_BM1385_global_arg(void)

{
  bool bVar1;
  int iVar2;
  uint local_2c;
  uint local_28;
  uint local_24;
  uint local_20;
  uint local_1c;
  uint local_18;
  uint local_14;
  uint local_10;
  
  local_1c = 0;
  local_20 = Conf._204_4_;
  local_24 = Conf._208_4_;
  local_28 = Conf._212_4_;
  local_2c = Conf._216_4_;
  reset_global_arg();
  printf("\n--- %s\n","reset_single_BM1385_global_arg");
  for (local_14 = 0; local_14 < 0x20; local_14 = local_14 + 1) {
    if ((local_20 & 1) != 0) {
      local_1c = local_1c + 1;
    }
    local_20 = local_20 >> 1;
    if ((local_24 & 1) != 0) {
      local_1c = local_1c + 1;
    }
    local_24 = local_24 >> 1;
    if ((local_28 & 1) != 0) {
      local_1c = local_1c + 1;
    }
    local_28 = local_28 >> 1;
    if ((local_2c & 1) != 0) {
      local_1c = local_1c + 1;
    }
    local_2c = local_2c >> 1;
  }
  bVar1 = false;
  while (!bVar1) {
    cgpu[131836] = 0;
    gRepeated_Nonce_Id = 0;
    gValid_Nonce_Num = 0;
    gSend_Work_Num = 0;
    for (local_18 = 0; local_18 < local_1c; local_18 = local_18 + 1) {
      iVar2 = *(int *)(cgpu + (local_18 + 0x402a) * 4 + 4);
      for (local_10 = 0; local_10 < (uint)Conf._64_4_; local_10 = local_10 + 1) {
        *(undefined4 *)(iVar2 + local_10 * 0x38 + 0x34) = 0;
      }
      *(undefined4 *)(gAsic_Core_Nonce_Num + local_18 * 4) = 0;
    }
    bVar1 = true;
  }
  return;
}

