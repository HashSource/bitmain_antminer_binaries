
void reset_single_BM1385_global_arg(void)

{
  int iVar1;
  uint local_2c;
  uint local_28;
  uint local_24;
  uint local_20;
  uint local_1c;
  uint local_18;
  uint local_14;
  uint local_10;
  uint local_c;
  
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
  for (local_c = 0; local_c < 0x10; local_c = local_c + 1) {
    cgpu[local_c + 0x20338] = 0;
    *(undefined4 *)(gRepeated_Nonce_Id + local_c * 4) = 0;
    *(undefined4 *)(gValid_Nonce_Num + local_c * 4) = 0;
    *(undefined4 *)(gSend_Work_Num + local_c * 4) = 0;
    for (local_18 = 0; local_18 < local_1c; local_18 = local_18 + 1) {
      iVar1 = *(int *)(cgpu + (local_18 + 0x402a) * 4 + 4);
      for (local_10 = 0; local_10 < (uint)Conf._64_4_; local_10 = local_10 + 1) {
        *(undefined4 *)(iVar1 + local_10 * 0x74 + (local_c + 0xc) * 4 + 4) = 0;
      }
      *(undefined4 *)(gAsic_Core_Nonce_Num + (local_c * 0x4000 + local_18) * 4) = 0;
    }
  }
  return;
}

