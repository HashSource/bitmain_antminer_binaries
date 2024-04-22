
undefined4 pkey_rsa_init(int param_1)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)CRYPTO_malloc(0x2c,DAT_000fd9d4,0x67);
  if (puVar1 != (undefined4 *)0x0) {
    *puVar1 = 0x400;
    puVar1[1] = 0;
    puVar1[5] = 0;
    puVar1[6] = 0;
    puVar1[8] = 0;
    puVar1[9] = 0;
    puVar1[10] = 0;
    puVar1[4] = 1;
    puVar1[7] = 0xfffffffe;
    *(undefined4 **)(param_1 + 0x14) = puVar1;
    *(undefined4 **)(param_1 + 0x20) = puVar1 + 2;
    *(undefined4 *)(param_1 + 0x24) = 2;
    return 1;
  }
  return 0;
}

