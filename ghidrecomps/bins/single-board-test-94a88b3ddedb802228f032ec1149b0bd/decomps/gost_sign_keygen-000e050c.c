
undefined4 gost_sign_keygen(int param_1)

{
  BIGNUM *pBVar1;
  BN_CTX *c;
  undefined4 uVar2;
  
  pBVar1 = BN_new();
  *(BIGNUM **)(param_1 + 0x1c) = pBVar1;
  if (pBVar1 == (BIGNUM *)0x0) {
    ERR_GOST_error(0x8e,0x41,DAT_000e05a0,0x128);
    uVar2 = 0;
  }
  else {
    BN_rand_range(pBVar1,*(BIGNUM **)(param_1 + 0x10));
    if (*(int *)(param_1 + 0x14) == 0) {
      ERR_GOST_error(0x6e,0x71,DAT_000e05a0,0xe9);
      uVar2 = 0;
    }
    else {
      c = BN_CTX_new();
      if (c == (BN_CTX *)0x0) {
        ERR_GOST_error(0x6e,0x41,DAT_000e05a0,0xee);
        uVar2 = 0;
      }
      else {
        pBVar1 = BN_new();
        *(BIGNUM **)(param_1 + 0x18) = pBVar1;
        if (pBVar1 == (BIGNUM *)0x0) {
          ERR_GOST_error(0x6e,0x41,DAT_000e05a0,0xf4);
          BN_CTX_free(c);
          uVar2 = 0;
        }
        else {
          BN_mod_exp(pBVar1,*(BIGNUM **)(param_1 + 0x14),*(BIGNUM **)(param_1 + 0x1c),
                     *(BIGNUM **)(param_1 + 0xc),c);
          BN_CTX_free(c);
          uVar2 = 1;
        }
      }
    }
  }
  return uVar2;
}

