
undefined4 chacha20_poly1305_init_key(int param_1,byte *param_2,void *param_3,undefined4 param_4)

{
  size_t __n;
  uint *puVar1;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined1 auStack_20 [4];
  
  if (param_2 != (byte *)0x0 || param_3 != (void *)0x0) {
    puVar1 = *(uint **)(param_1 + 0x60);
    puVar1[0x2e] = 0;
    puVar1[0x2f] = 0;
    puVar1[0x32] = 0xffffffff;
    puVar1[0x2a] = 0;
    puVar1[0x2b] = 0;
    puVar1[0x2c] = 0;
    puVar1[0x2d] = 0;
    if (param_3 == (void *)0x0) {
      if (param_2 != (byte *)0x0) {
        *puVar1 = (uint)*param_2 | (uint)param_2[1] << 8 | (uint)param_2[2] << 0x10 |
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
        puVar1[7] = (uint)param_2[0x1c] | (uint)param_2[0x1e] << 0x10 | (uint)param_2[0x1d] << 8 |
                    (uint)param_2[0x1f] << 0x18;
      }
      puVar1[0x1c] = 0;
    }
    else {
      __n = puVar1[0x31];
      local_30 = 0;
      local_2c = 0;
      local_28 = 0;
      local_24 = 0;
      if ((int)__n < 0x11) {
        memcpy(auStack_20 + -__n,param_3,__n);
      }
      chacha_init_key(param_1,param_2,&local_30,param_4);
      puVar1[0x1e] = puVar1[9];
      puVar1[0x1f] = puVar1[10];
      puVar1[0x20] = puVar1[0xb];
    }
  }
  return 1;
}

