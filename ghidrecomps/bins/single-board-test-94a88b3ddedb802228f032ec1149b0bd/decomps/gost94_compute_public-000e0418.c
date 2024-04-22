
undefined4 gost94_compute_public(int param_1)

{
  BN_CTX *c;
  BIGNUM *r;
  undefined4 uVar1;
  
  if (*(int *)(param_1 + 0x14) == 0) {
    ERR_GOST_error(0x6e,0x71,DAT_000e0484,0xe9);
    uVar1 = 0;
  }
  else {
    c = BN_CTX_new();
    if (c == (BN_CTX *)0x0) {
      ERR_GOST_error(0x6e,0x41,DAT_000e0484,0xee);
      uVar1 = 0;
    }
    else {
      r = BN_new();
      *(BIGNUM **)(param_1 + 0x18) = r;
      if (r == (BIGNUM *)0x0) {
        ERR_GOST_error(0x6e,0x41,DAT_000e0484,0xf4);
        BN_CTX_free(c);
        uVar1 = 0;
      }
      else {
        BN_mod_exp(r,*(BIGNUM **)(param_1 + 0x14),*(BIGNUM **)(param_1 + 0x1c),
                   *(BIGNUM **)(param_1 + 0xc),c);
        BN_CTX_free(c);
        uVar1 = 1;
      }
    }
  }
  return uVar1;
}

