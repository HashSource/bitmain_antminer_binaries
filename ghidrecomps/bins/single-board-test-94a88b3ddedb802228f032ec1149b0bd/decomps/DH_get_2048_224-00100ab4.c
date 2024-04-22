
DH * DH_get_2048_224(void)

{
  DH *dh;
  BIGNUM *pBVar1;
  DH *pDVar2;
  
  dh = DH_new();
  pDVar2 = dh;
  if (dh != (DH *)0x0) {
    pBVar1 = BN_dup(DAT_00100af0);
    dh->p = pBVar1;
    pBVar1 = BN_dup(DAT_00100af4);
    dh->g = pBVar1;
    pBVar1 = BN_dup(DAT_00100af8);
    dh->q = pBVar1;
    if (((dh->p == (BIGNUM *)0x0) || (pBVar1 == (BIGNUM *)0x0)) || (dh->g == (BIGNUM *)0x0)) {
      pDVar2 = (DH *)0x0;
      DH_free(dh);
    }
  }
  return pDVar2;
}

