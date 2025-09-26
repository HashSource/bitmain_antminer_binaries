
BN_MONT_CTX * ec_precompute_mont_data(int param_1)

{
  BN_CTX *ctx;
  int iVar1;
  BN_MONT_CTX *mont;
  
  ctx = BN_CTX_new();
  if (*(int *)(param_1 + 0x34) < 0) {
    if (*(BN_MONT_CTX **)(param_1 + 0xac) != (BN_MONT_CTX *)0x0) {
      BN_MONT_CTX_free(*(BN_MONT_CTX **)(param_1 + 0xac));
      *(undefined4 *)(param_1 + 0xac) = 0;
    }
    if (ctx == (BN_CTX *)0x0) {
      return (BN_MONT_CTX *)0x0;
    }
    mont = BN_MONT_CTX_new();
    *(BN_MONT_CTX **)(param_1 + 0xac) = mont;
    if (mont != (BN_MONT_CTX *)0x0) {
      iVar1 = BN_MONT_CTX_set(mont,(BIGNUM *)(param_1 + 8),ctx);
      mont = (BN_MONT_CTX *)0x1;
      if (iVar1 == 0) {
        BN_MONT_CTX_free(*(BN_MONT_CTX **)(param_1 + 0xac));
        *(undefined4 *)(param_1 + 0xac) = 0;
        mont = (BN_MONT_CTX *)0x0;
      }
    }
  }
  else {
    if (ctx == (BN_CTX *)0x0) {
      return (BN_MONT_CTX *)0x0;
    }
    mont = (BN_MONT_CTX *)0x0;
  }
  BN_CTX_free(ctx);
  return mont;
}

