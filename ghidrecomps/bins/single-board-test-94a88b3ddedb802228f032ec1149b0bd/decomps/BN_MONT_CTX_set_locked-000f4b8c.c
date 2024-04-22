
BN_MONT_CTX * BN_MONT_CTX_set_locked(BN_MONT_CTX **pmont,int lock,BIGNUM *mod,BN_CTX *ctx)

{
  BN_MONT_CTX *mont;
  int iVar1;
  BIGNUM *a;
  BN_MONT_CTX *pBVar2;
  BIGNUM *a_00;
  BIGNUM *a_01;
  
  CRYPTO_lock(5,lock,DAT_000f4c80,0x20c);
  pBVar2 = *pmont;
  CRYPTO_lock(6,lock,DAT_000f4c80,0x20e);
  if ((pBVar2 == (BN_MONT_CTX *)0x0) &&
     (mont = (BN_MONT_CTX *)CRYPTO_malloc(0x4c,DAT_000f4c80,0x155), mont != (BN_MONT_CTX *)0x0)) {
    a_01 = &mont->N;
    a_00 = &mont->RR;
    mont->ri = 0;
    BN_init(a_00);
    a = &mont->Ni;
    BN_init(a_01);
    BN_init(a);
    mont->n0[1] = 0;
    mont->n0[0] = 0;
    mont->flags = 1;
    iVar1 = BN_MONT_CTX_set(mont,mod,ctx);
    if (iVar1 == 0) {
      BN_free(a_00);
      BN_free(a_01);
      BN_free(a);
      if (mont->flags << 0x1f < 0) {
        CRYPTO_free(mont);
      }
    }
    else {
      CRYPTO_lock(9,lock,DAT_000f4c80,0x223);
      if (*pmont == (BN_MONT_CTX *)0x0) {
        *pmont = mont;
      }
      else {
        BN_free(a_00);
        BN_free(a_01);
        BN_free(a);
        if (mont->flags << 0x1f < 0) {
          CRYPTO_free(mont);
        }
        mont = *pmont;
      }
      CRYPTO_lock(10,lock,DAT_000f4c80,0x229);
      pBVar2 = mont;
    }
  }
  return pBVar2;
}

