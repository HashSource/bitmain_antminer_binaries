
undefined4 pkey_hmac_init(int param_1)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)CRYPTO_malloc(0xe4,DAT_000e09d4,0x4e);
  if (puVar1 != (undefined4 *)0x0) {
    *puVar1 = 0;
    puVar1[3] = 0;
    puVar1[1] = 0;
    puVar1[4] = 0;
    puVar1[2] = 4;
    HMAC_CTX_init((HMAC_CTX *)(puVar1 + 5));
    *(undefined4 *)(param_1 + 0x24) = 0;
    *(undefined4 **)(param_1 + 0x14) = puVar1;
    return 1;
  }
  return 0;
}

