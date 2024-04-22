
void chain_inactive(byte param_1)

{
  uint local_34;
  int local_30;
  undefined4 local_2c;
  byte local_28;
  byte local_27;
  byte local_26;
  byte local_25;
  byte local_24;
  FILE *local_20;
  uint local_1c;
  uint local_18;
  FILE *local_14;
  
  local_25 = 0;
  local_24 = 5;
  local_34 = 0;
  local_30 = 0;
  local_2c = 0;
  if (cgpu._2562268_4_ == 0) {
    local_28 = 0x55;
    local_27 = 5;
    local_26 = 0;
    local_25 = 0;
    local_24 = CRC5(&local_28,0x20);
    if (3 < log_level) {
      local_20 = fopen(log_file,"a+");
      if (local_20 != (FILE *)0x0) {
        fprintf(local_20,
                "%s:%d: %s: buf[0]=0x%x, buf[1]=0x%x, buf[2]=0x%x, buf[3]=0x%x, buf[4]=0x%x\n",
                "driver-bitmain.c",0xbee,"chain_inactive",(uint)local_28,(uint)local_27,
                (uint)local_26,(uint)local_25,(uint)local_24);
      }
      fclose(local_20);
    }
    local_34 = (uint)local_26 << 8 | (uint)local_28 << 0x18 | (uint)local_27 << 0x10 |
               (uint)local_25;
    local_30 = (uint)local_24 << 0x18;
    set_BC_command_buffer(&local_34);
    local_18 = get_BC_write_command();
    local_1c = local_18 & 0xfff0ffff | (uint)param_1 << 0x10 | 0x80800000;
    set_BC_write_command(local_1c);
  }
  else {
    local_28 = 0x85;
    local_27 = 0;
    local_26 = 0;
    local_25 = CRC5(&local_28,0x1b);
    if (3 < log_level) {
      local_14 = fopen(log_file,"a+");
      if (local_14 != (FILE *)0x0) {
        fprintf(local_14,"%s:%d: %s: buf[0]=0x%x, buf[1]=0x%x, buf[2]=0x%x, buf[3]=0x%x\n",
                "driver-bitmain.c",0xbde,"chain_inactive",(uint)local_28,(uint)local_27,
                (uint)local_26,(uint)local_25);
      }
      fclose(local_14);
    }
    local_34 = (uint)local_26 << 8 | (uint)local_28 << 0x18 | (uint)local_27 << 0x10 |
               (uint)local_25;
    set_BC_command_buffer(&local_34);
    local_18 = get_BC_write_command();
    local_1c = local_18 & 0xfff0ffff | (uint)param_1 << 0x10 | 0x80800000;
    set_BC_write_command(local_1c);
  }
  return;
}

