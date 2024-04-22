
int get_ideal_rate_from_eeprom(void)

{
  int iVar1;
  undefined auStack_24 [4];
  int local_20;
  int local_1c;
  undefined4 local_18;
  int local_14;
  int local_10;
  int local_c;
  
  local_10 = 0;
  local_14 = get_asic_num_per_chain();
  for (local_c = 0; local_c < 0x10; local_c = local_c + 1) {
    if (*(int *)(cgpu + (local_c + 0x9c638) * 4) != 0) {
      iVar1 = is_S9_Hydro();
      if (iVar1 == 0) {
        iVar1 = is_S9i();
        if (iVar1 == 0) {
          local_10 = *(int *)(local_14 + local_c * 0x80 + 0x1a3fbbe) + local_10;
        }
        else {
          local_10 = (((byte)chain_pic_buf[local_c * 0x80 + 0x22] & 0xf) << 0xc |
                     (byte)chain_pic_buf[local_c * 0x80 + 0x1c] & 0xf |
                     ((byte)chain_pic_buf[local_c * 0x80 + 0x1e] & 0xf) << 4 |
                     ((byte)chain_pic_buf[local_c * 0x80 + 0x20] & 0xf) << 8) + local_10;
        }
      }
      else {
        local_18 = get_board_index_S9_Hydro(local_c,&local_1c);
        getPICChainIndexOffset(local_18,&local_20,auStack_24);
        local_10 = *(int *)(local_14 + local_1c * 4 + local_20 * 0x80 + 0x1a3fbbe) + local_10;
      }
    }
  }
  return local_10;
}

