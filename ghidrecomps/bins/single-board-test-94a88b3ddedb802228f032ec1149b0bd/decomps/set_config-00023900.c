
void set_config(int param_1,char param_2,undefined param_3,undefined param_4,undefined4 param_5)

{
  undefined uVar1;
  uint local_28;
  uint local_24;
  int local_20;
  uint local_1c;
  uint local_18;
  byte local_14;
  uint local_10;
  uint local_c;
  
  local_14 = 0;
  local_28 = 0;
  local_24 = 0;
  local_20 = 0;
  uVar1 = 0x48;
  if (param_2 != '\0') {
    uVar1 = 0x58;
  }
  local_1c = CONCAT13(param_4,CONCAT12(param_3,CONCAT11(9,uVar1)));
  local_18 = CONCAT13((char)param_5,
                      CONCAT12((char)((uint)param_5 >> 8),
                               CONCAT11((char)((uint)param_5 >> 0x10),(char)((uint)param_5 >> 0x18))
                              ));
  local_14 = CRC5(&local_1c,0x40);
  local_28 = (local_1c >> 0x10 & 0xff) << 8 | local_1c << 0x18 | (local_1c >> 8 & 0xff) << 0x10 |
             local_1c >> 0x18;
  local_24 = (local_18 >> 0x10 & 0xff) << 8 | local_18 << 0x18 | (local_18 >> 8 & 0xff) << 0x10 |
             local_18 >> 0x18;
  local_20 = (uint)local_14 << 0x18;
  set_BC_command_buffer(&local_28);
  local_c = get_BC_write_command();
  local_10 = local_c & 0xfff0ffff | param_1 << 0x10 | 0x80800000;
  set_BC_write_command(local_10);
  return;
}

