
void * CRYPTO_gcm128_new(undefined4 param_1,undefined4 param_2)

{
  void *pvVar1;
  
  pvVar1 = CRYPTO_malloc(0x178,DAT_000ed248,0x6bb);
  if (pvVar1 != (void *)0x0) {
    CRYPTO_gcm128_init(pvVar1,param_1,param_2);
  }
  return pvVar1;
}

