
void set_tickmask(undefined4 param_1)

{
  uint local_2c;
  uint local_28;
  int local_24;
  uint local_20;
  uint local_1c;
  byte local_18;
  uint local_14;
  uint local_10;
  uint local_c;
  
  local_20 = 0;
  local_1c = 0;
  local_18 = 0;
  local_2c = 0;
  local_28 = 0;
  local_24 = 0;
  printf("\n--- %s\n","set_tickmask");
  for (local_c = 0; local_c < 0x10; local_c = local_c + 1) {
    if (((*(int *)(cgpu + (local_c + 0x9c638) * 4) == 1) && (testDone[local_c] != '\x01')) &&
       (cgpu._2562268_4_ == 0)) {
      local_20 = CONCAT13((char)TICKET_MASK,0x958);
      local_1c = CONCAT13((char)param_1,
                          CONCAT12((char)((uint)param_1 >> 8),
                                   CONCAT11((char)((uint)param_1 >> 0x10),
                                            (char)((uint)param_1 >> 0x18))));
      local_18 = CRC5(&local_20,0x40);
      local_2c = (local_20 >> 0x10 & 0xff) << 8 | local_20 << 0x18 | (local_20 >> 8 & 0xff) << 0x10
                 | local_20 >> 0x18;
      local_28 = (local_1c >> 0x10 & 0xff) << 8 | local_1c << 0x18 | (local_1c >> 8 & 0xff) << 0x10
                 | local_1c >> 0x18;
      local_24 = (uint)local_18 << 0x18;
      printf("%s: cmd_buf[0]=0x%x, cmd_buf[1]=0x%x, cmd_buf[2]=0x%x\n","set_tickmask",local_2c,
             local_28,local_24);
      set_BC_command_buffer(&local_2c);
      local_10 = get_BC_write_command();
      local_14 = local_10 & 0xfff0ffff | local_c << 0x10 | 0x80800000;
      set_BC_write_command(local_14);
    }
  }
  return;
}

