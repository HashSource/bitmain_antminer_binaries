
undefined4 pkey_dh_init(int param_1)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)CRYPTO_malloc(0x38,DAT_0010072c,0x65);
  if (puVar1 != (undefined4 *)0x0) {
    *puVar1 = 0x400;
    puVar1[3] = 0xffffffff;
    puVar1[1] = 2;
    puVar1[2] = 0;
    puVar1[4] = 0;
    puVar1[5] = 0;
    puVar1[9] = 0;
    puVar1[10] = 0;
    puVar1[0xb] = 0;
    puVar1[0xc] = 0;
    puVar1[0xd] = 0;
    *(undefined *)(puVar1 + 8) = 1;
    *(undefined4 *)(param_1 + 0x24) = 2;
    *(undefined4 **)(param_1 + 0x14) = puVar1;
    *(undefined4 **)(param_1 + 0x20) = puVar1 + 6;
    return 1;
  }
  return 0;
}

