
undefined4 pkey_dsa_init(int param_1)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)CRYPTO_malloc(0x18,DAT_000ff6c8,0x54);
  if (puVar1 != (undefined4 *)0x0) {
    puVar1[1] = 0xa0;
    *puVar1 = 0x400;
    puVar1[2] = 0;
    puVar1[5] = 0;
    *(undefined4 **)(param_1 + 0x14) = puVar1;
    *(undefined4 **)(param_1 + 0x20) = puVar1 + 3;
    *(undefined4 *)(param_1 + 0x24) = 2;
    return 1;
  }
  return 0;
}

