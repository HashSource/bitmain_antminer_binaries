
void bitmain_set_pic_voltage(byte param_1)

{
  uint uVar1;
  undefined uVar2;
  uint local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined local_20;
  uint local_1c;
  uint local_18;
  byte local_11;
  int local_10;
  byte local_9;
  
  local_28 = 0;
  local_24 = 0;
  local_20 = 0;
  local_34 = 0;
  local_30 = 0;
  local_2c = 0;
  local_11 = param_1;
  printf("%s: n = %d\n","bitmain_set_pic_voltage",(uint)param_1);
  local_28._0_3_ = CONCAT12(local_11,0xb0ab);
  uVar2 = CRC5(&local_28,0x1b);
  uVar1 = local_28;
  local_28 = CONCAT13(uVar2,(undefined3)local_28) | 0xc0000000;
  printf("set_pic_voltage buf[0]: 0x%x, buf[1]: 0x%x, buf[2]: 0x%x, buf[3]: 0x%x\n",uVar1 & 0xff,
         uVar1 >> 8 & 0xff,uVar1 >> 0x10 & 0xff,local_28 >> 0x18);
  local_34 = (local_28 >> 0x10 & 0xff) << 8 | local_28 << 0x18 | (local_28 >> 8 & 0xff) << 0x10 |
             local_28 >> 0x18;
  for (local_9 = 0; local_9 < 3; local_9 = local_9 + 1) {
    for (local_10 = 0; local_10 < 0x10; local_10 = local_10 + 1) {
      if (*(int *)(cgpu + (local_10 + 0x9c638) * 4) == 1) {
        set_BC_command_buffer(&local_34);
        local_18 = get_BC_write_command();
        local_1c = local_18 & 0xfff0ffff | local_10 << 0x10 | 0x80800000;
        set_BC_write_command(local_1c);
      }
    }
  }
  return;
}

