
void enable_read_temperature_from_asic(int param_1,undefined param_2)

{
  uint local_2c;
  uint local_28;
  int local_24;
  uint local_20;
  uint local_1c;
  byte local_18;
  uint local_14;
  uint local_10;
  int local_c;
  
  local_18 = 0;
  local_2c = 0;
  local_28 = 0;
  local_24 = 0;
  if (((*(int *)(cgpu + (param_1 + 0x9c638) * 4) == 1) && (testDone[param_1] != '\x01')) &&
     (cgpu._2562268_4_ == 0)) {
    local_20 = CONCAT13((char)MISC_CONTROL,CONCAT12(param_2,0x948));
    local_1c = CONCAT13(cgpu[2562398] << 5,
                        CONCAT12(cgpu[2562397] << 6 | cgpu[2562356] & 0x1f,
                                 CONCAT11(cgpu[2562396],0x40))) | 0x2000;
    local_c = param_1;
    local_18 = CRC5(&local_20,0x40);
    local_2c = (local_20 >> 0x10 & 0xff) << 8 | local_20 << 0x18 | (local_20 >> 8 & 0xff) << 0x10 |
               local_20 >> 0x18;
    local_28 = (local_1c >> 0x10 & 0xff) << 8 | local_1c << 0x18 | (local_1c >> 8 & 0xff) << 0x10 |
               local_1c >> 0x18;
    local_24 = (uint)local_18 << 0x18;
    set_BC_command_buffer(&local_2c);
    local_10 = get_BC_write_command();
    local_14 = local_10 & 0xfff0ffff | local_c << 0x10 | 0x80800000;
    set_BC_write_command(local_14);
  }
  return;
}

