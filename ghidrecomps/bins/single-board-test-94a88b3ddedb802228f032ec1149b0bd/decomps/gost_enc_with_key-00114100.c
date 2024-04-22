
void gost_enc_with_key(uint *param_1,byte *param_2,undefined4 param_3,undefined4 param_4)

{
  *param_1 = (uint)param_2[2] << 0x10 | (uint)param_2[1] << 8 | (uint)*param_2 |
             (uint)param_2[3] << 0x18;
  param_1[1] = (uint)param_2[6] << 0x10 | (uint)param_2[5] << 8 | (uint)param_2[4] |
               (uint)param_2[7] << 0x18;
  param_1[2] = (uint)param_2[10] << 0x10 | (uint)param_2[9] << 8 | (uint)param_2[8] |
               (uint)param_2[0xb] << 0x18;
  param_1[3] = (uint)param_2[0xe] << 0x10 | (uint)param_2[0xd] << 8 | (uint)param_2[0xc] |
               (uint)param_2[0xf] << 0x18;
  param_1[4] = (uint)param_2[0x12] << 0x10 | (uint)param_2[0x11] << 8 | (uint)param_2[0x10] |
               (uint)param_2[0x13] << 0x18;
  param_1[5] = (uint)param_2[0x16] << 0x10 | (uint)param_2[0x15] << 8 | (uint)param_2[0x14] |
               (uint)param_2[0x17] << 0x18;
  param_1[6] = (uint)param_2[0x1a] << 0x10 | (uint)param_2[0x19] << 8 | (uint)param_2[0x18] |
               (uint)param_2[0x1b] << 0x18;
  param_1[7] = (uint)param_2[0x1e] << 0x10 | (uint)param_2[0x1d] << 8 | (uint)param_2[0x1c] |
               (uint)param_2[0x1f] << 0x18;
  gostcrypt(param_1,param_3,param_4);
  return;
}

