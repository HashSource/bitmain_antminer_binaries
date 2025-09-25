
void IDEA_ecb_encrypt(byte *param_1,undefined1 *param_2,undefined4 param_3)

{
  uint local_20;
  uint local_1c;
  
  local_20 = (uint)param_1[3] | (uint)param_1[1] << 0x10 | (uint)*param_1 << 0x18 |
             (uint)param_1[2] << 8;
  local_1c = (uint)param_1[5] << 0x10 | (uint)param_1[4] << 0x18 | (uint)param_1[7] |
             (uint)param_1[6] << 8;
  IDEA_encrypt(&local_20,param_3);
  param_2[3] = (char)local_20;
  *param_2 = (char)(local_20 >> 0x18);
  param_2[1] = (char)(local_20 >> 0x10);
  param_2[2] = (char)(local_20 >> 8);
  param_2[7] = (char)local_1c;
  param_2[4] = (char)(local_1c >> 0x18);
  param_2[5] = (char)(local_1c >> 0x10);
  param_2[6] = (char)(local_1c >> 8);
  return;
}

