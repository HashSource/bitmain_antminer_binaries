
void power_set_da_value(undefined1 param_1)

{
  undefined1 auStack_34 [32];
  byte local_14 [8];
  ushort local_c;
  short local_a;
  
  local_14[0] = 0x55;
  local_14[1] = 0xaa;
  local_14[2] = 6;
  local_14[3] = 0x83;
  local_14[4] = 0;
  local_14[5] = 0;
  local_14[6] = 0;
  local_14[7] = 0;
  memset(auStack_34,0,0x20);
  local_a = 0;
  local_14[4] = param_1;
  for (local_c = 2; local_c < 6; local_c = local_c + 1) {
    local_a = local_a + (ushort)local_14[local_c];
  }
  local_14[6] = (char)local_a;
  local_14[7] = (char)((ushort)local_a >> 8);
  power_send_cmd(local_14,8,auStack_34,8);
  return;
}

