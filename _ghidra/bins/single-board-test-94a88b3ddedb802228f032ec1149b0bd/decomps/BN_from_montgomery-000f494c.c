
int BN_from_montgomery(BIGNUM *r,BIGNUM *a,BN_MONT_CTX *mont,BN_CTX *ctx)

{
  BIGNUM *a_00;
  BIGNUM *pBVar1;
  int iVar2;
  
  BN_CTX_start(ctx);
  a_00 = BN_CTX_get(ctx);
  if ((a_00 == (BIGNUM *)0x0) || (pBVar1 = BN_copy(a_00,a), pBVar1 == (BIGNUM *)0x0)) {
    iVar2 = 0;
  }
  else {
    iVar2 = BN_from_montgomery_word(r,a_00,mont);
  }
  BN_CTX_end(ctx);
  return iVar2;
}

