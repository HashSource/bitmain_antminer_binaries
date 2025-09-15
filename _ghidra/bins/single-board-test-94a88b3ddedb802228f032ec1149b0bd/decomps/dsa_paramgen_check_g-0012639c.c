
int dsa_paramgen_check_g(int param_1)

{
  BN_CTX *ctx;
  BIGNUM *pBVar1;
  int iVar2;
  BN_MONT_CTX *mont;
  uint uVar3;
  BIGNUM *pBVar4;
  
  ctx = BN_CTX_new();
  if (ctx == (BN_CTX *)0x0) {
    iVar2 = -1;
  }
  else {
    BN_CTX_start(ctx);
    pBVar4 = *(BIGNUM **)(param_1 + 0x14);
    pBVar1 = BN_value_one();
    iVar2 = BN_cmp(pBVar4,pBVar1);
    if ((iVar2 < 1) ||
       (iVar2 = BN_cmp(*(BIGNUM **)(param_1 + 0x14),*(BIGNUM **)(param_1 + 0xc)), -1 < iVar2)) {
      iVar2 = 0;
    }
    else {
      pBVar1 = BN_CTX_get(ctx);
      if ((pBVar1 == (BIGNUM *)0x0) || (mont = BN_MONT_CTX_new(), mont == (BN_MONT_CTX *)0x0)) {
        iVar2 = -1;
        BN_CTX_end(ctx);
      }
      else {
        iVar2 = BN_MONT_CTX_set(mont,*(BIGNUM **)(param_1 + 0xc),ctx);
        if ((iVar2 == 0) ||
           (iVar2 = BN_mod_exp_mont(pBVar1,*(BIGNUM **)(param_1 + 0x14),*(BIGNUM **)(param_1 + 0x10)
                                    ,*(BIGNUM **)(param_1 + 0xc),ctx,mont), iVar2 == 0)) {
          iVar2 = -1;
        }
        else {
          pBVar4 = BN_value_one();
          uVar3 = BN_cmp(pBVar1,pBVar4);
          iVar2 = 1 - uVar3;
          if (1 < uVar3) {
            iVar2 = 0;
          }
        }
        BN_CTX_end(ctx);
        BN_MONT_CTX_free(mont);
      }
      BN_CTX_free(ctx);
    }
  }
  return iVar2;
}

