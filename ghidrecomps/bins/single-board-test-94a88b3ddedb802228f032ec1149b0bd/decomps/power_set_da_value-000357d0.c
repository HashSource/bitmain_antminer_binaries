
void power_set_da_value(undefined param_1)

{
  undefined auStack_34 [32];
  undefined4 local_14;
  undefined4 local_10;
  ushort local_c;
  short local_a;
  
  local_14 = DAT_001334cc;
  local_10 = DAT_001334d0;
  memset(auStack_34,0,0x20);
  local_a = 0;
  local_10 = CONCAT31(local_10._1_3_,param_1);
  for (local_c = 2; local_c < 6; local_c = local_c + 1) {
    local_a = local_a + (ushort)*(byte *)((int)&local_14 + (uint)local_c);
  }
  local_10 = CONCAT13((char)((ushort)local_a >> 8),CONCAT12((char)local_a,(undefined2)local_10));
  power_send_cmd(&local_14,8,auStack_34,8);
  return;
}

