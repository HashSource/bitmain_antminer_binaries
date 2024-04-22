
undefined4 * pkey_hmac_copy(int param_1,int param_2)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  HMAC_CTX *ctx;
  undefined4 *puVar3;
  
  puVar1 = (undefined4 *)CRYPTO_malloc(0xe4,DAT_000e0ad0,0x4e);
  puVar2 = puVar1;
  if (puVar1 != (undefined4 *)0x0) {
    ctx = (HMAC_CTX *)(puVar1 + 5);
    *puVar1 = 0;
    puVar1[3] = 0;
    puVar1[1] = 0;
    puVar1[4] = 0;
    puVar1[2] = 4;
    HMAC_CTX_init(ctx);
    *(undefined4 **)(param_1 + 0x14) = puVar1;
    puVar3 = *(undefined4 **)(param_2 + 0x14);
    *(undefined4 *)(param_1 + 0x24) = 0;
    *puVar1 = *puVar3;
    HMAC_CTX_init(ctx);
    puVar2 = (undefined4 *)HMAC_CTX_copy(ctx,(HMAC_CTX *)(puVar3 + 5));
    if (puVar2 != (undefined4 *)0x0) {
      if ((void *)puVar3[3] != (void *)0x0) {
        puVar2 = (undefined4 *)
                 ASN1_OCTET_STRING_set((ASN1_STRING *)(puVar1 + 1),(void *)puVar3[3],puVar3[1]);
        if (puVar2 != (undefined4 *)0x0) {
          puVar2 = (undefined4 *)0x1;
        }
        return puVar2;
      }
      return (undefined4 *)0x1;
    }
  }
  return puVar2;
}

