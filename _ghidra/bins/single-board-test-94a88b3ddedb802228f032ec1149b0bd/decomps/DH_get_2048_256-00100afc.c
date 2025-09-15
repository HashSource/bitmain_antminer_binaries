
DH * DH_get_2048_256(void)

{
  DH *dh;
  BIGNUM *pBVar1;
  DH *pDVar2;
  
  dh = DH_new();
  pDVar2 = dh;
  if (dh != (DH *)0x0) {
    pBVar1 = BN_dup((BIGNUM *)_bignum_dh2048_256_p_8258);
    dh->p = pBVar1;
    pBVar1 = BN_dup((BIGNUM *)_bignum_dh2048_256_g_8260);
    dh->g = pBVar1;
    pBVar1 = BN_dup((BIGNUM *)_bignum_dh2048_256_q_8259);
    dh->q = pBVar1;
    if (((dh->p == (BIGNUM *)0x0) || (pBVar1 == (BIGNUM *)0x0)) || (dh->g == (BIGNUM *)0x0)) {
      pDVar2 = (DH *)0x0;
      DH_free(dh);
    }
  }
  return pDVar2;
}

