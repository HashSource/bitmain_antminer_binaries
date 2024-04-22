
undefined4 flash_pic_badcore_num(undefined param_1,int param_2)

{
  uint uVar1;
  undefined4 *puVar2;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  uint local_1c;
  byte local_18;
  byte local_17;
  byte local_16;
  byte local_15;
  uint local_14;
  
  local_2c = 0;
  local_28 = 0;
  local_24 = 0;
  local_20 = 0;
  local_14 = 0;
  local_15 = 0xf;
  local_16 = 0x80;
  local_17 = 0xf;
  local_18 = 0x9f;
  local_1c = 0;
  set_pic_iic_flash_addr_pointer(param_1,0xf,0x80);
  local_1c = (((uint)local_17 * 0x100 + (uint)local_18) - ((uint)local_16 + (uint)local_15 * 0x100))
             + 1;
  for (local_14 = 0; uVar1 = (local_1c >> 5) * 4, local_14 <= uVar1 && uVar1 - local_14 != 0;
      local_14 = local_14 + 1) {
    puVar2 = (undefined4 *)(local_14 * 0x10 + param_2);
    local_2c = *puVar2;
    local_28 = puVar2[1];
    local_24 = puVar2[2];
    local_20 = puVar2[3];
    send_data_to_pic_flash(param_1,&local_2c);
    write_data_into_pic_flash(param_1);
  }
  return 0;
}

