
undefined4 chacha_init_key(int param_1,byte *param_2,byte *param_3)

{
  uint *puVar1;
  
  puVar1 = *(uint **)(param_1 + 0x60);
  if (param_2 != (byte *)0x0) {
    *puVar1 = (uint)*param_2 | (uint)param_2[2] << 0x10 | (uint)param_2[1] << 8 |
              (uint)param_2[3] << 0x18;
    puVar1[1] = (uint)param_2[4] | (uint)param_2[6] << 0x10 | (uint)param_2[5] << 8 |
                (uint)param_2[7] << 0x18;
    puVar1[2] = (uint)param_2[8] | (uint)param_2[10] << 0x10 | (uint)param_2[9] << 8 |
                (uint)param_2[0xb] << 0x18;
    puVar1[3] = (uint)param_2[0xc] | (uint)param_2[0xe] << 0x10 | (uint)param_2[0xd] << 8 |
                (uint)param_2[0xf] << 0x18;
    puVar1[4] = (uint)param_2[0x10] | (uint)param_2[0x12] << 0x10 | (uint)param_2[0x11] << 8 |
                (uint)param_2[0x13] << 0x18;
    puVar1[5] = (uint)param_2[0x14] | (uint)param_2[0x16] << 0x10 | (uint)param_2[0x15] << 8 |
                (uint)param_2[0x17] << 0x18;
    puVar1[6] = (uint)param_2[0x18] | (uint)param_2[0x1a] << 0x10 | (uint)param_2[0x19] << 8 |
                (uint)param_2[0x1b] << 0x18;
    puVar1[7] = (uint)param_2[0x1e] << 0x10 | (uint)param_2[0x1d] << 8 | (uint)param_2[0x1c] |
                (uint)param_2[0x1f] << 0x18;
  }
  if (param_3 != (byte *)0x0) {
    puVar1[8] = (uint)*param_3 | (uint)param_3[1] << 8 | (uint)param_3[2] << 0x10 |
                (uint)param_3[3] << 0x18;
    puVar1[9] = (uint)param_3[4] | (uint)param_3[5] << 8 | (uint)param_3[6] << 0x10 |
                (uint)param_3[7] << 0x18;
    puVar1[10] = (uint)param_3[8] | (uint)param_3[9] << 8 | (uint)param_3[10] << 0x10 |
                 (uint)param_3[0xb] << 0x18;
    puVar1[0xb] = (uint)param_3[0xe] << 0x10 | (uint)param_3[0xd] << 8 | (uint)param_3[0xc] |
                  (uint)param_3[0xf] << 0x18;
  }
  puVar1[0x1c] = 0;
  return 1;
}

