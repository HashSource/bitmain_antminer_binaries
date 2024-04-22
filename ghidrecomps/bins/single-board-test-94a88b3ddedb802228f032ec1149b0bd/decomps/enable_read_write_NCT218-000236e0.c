
void enable_read_write_NCT218(void)

{
  uint local_30;
  uint local_2c;
  int local_28;
  uint local_24;
  uint local_20;
  byte local_1c;
  uint local_18;
  uint local_14;
  int local_10;
  uint local_c;
  
  local_24 = 0;
  local_20 = 0;
  local_1c = 0;
  local_30 = 0;
  local_2c = 0;
  local_28 = 0;
  printf("\n--- %s\n","enable_read_write_NCT218");
  if ((Conf._128_4_ == 0) && (conf._112_4_ == 1)) {
    for (local_10 = 0; local_10 < 4; local_10 = local_10 + 1) {
      if (local_10 == 0) {
        local_c = (uint)conf[120];
      }
      if (local_10 == 1) {
        local_c = (uint)conf[121];
      }
      if (local_10 == 2) {
        local_c = (uint)conf[122];
      }
      if (local_10 == 3) {
        local_c = (uint)conf[123];
      }
      if (local_c != 0) {
        for (local_10 = 0; local_10 < 0x10; local_10 = local_10 + 1) {
          if ((*(int *)(cgpu + (local_10 + 0x9c638) * 4) == 1) && (cgpu._2562268_4_ == 0)) {
            local_24 = CONCAT13((char)MISC_CONTROL,
                                CONCAT12((char)((local_c + 0x7fffffff & 0xff) << 1),0x948));
            local_20 = CONCAT13(cgpu[2562398] << 5,
                                CONCAT12(cgpu[2562397] << 6 | cgpu[2562356] & 0x1f,
                                         CONCAT11(cgpu[2562396],0x40))) | 0x2000;
            local_1c = CRC5(&local_24,0x40);
            local_30 = (local_24 >> 0x10 & 0xff) << 8 |
                       local_24 << 0x18 | (local_24 >> 8 & 0xff) << 0x10 | local_24 >> 0x18;
            local_2c = (local_20 >> 0x10 & 0xff) << 8 |
                       local_20 << 0x18 | (local_20 >> 8 & 0xff) << 0x10 | local_20 >> 0x18;
            local_28 = (uint)local_1c << 0x18;
            set_BC_command_buffer(&local_30);
            local_14 = get_BC_write_command();
            local_18 = local_14 & 0xfff0ffff | local_10 << 0x10 | 0x80800000;
            set_BC_write_command(local_18);
          }
        }
      }
    }
  }
  return;
}

