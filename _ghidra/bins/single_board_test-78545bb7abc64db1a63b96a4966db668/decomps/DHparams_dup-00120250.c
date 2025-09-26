
DH * DHparams_dup(DH *param_1)

{
  DH *dh;
  int iVar1;
  uchar *puVar2;
  BIGNUM *pBVar3;
  BIGNUM *pBVar4;
  
  dh = DH_new();
  if (dh != (DH *)0x0) {
    pBVar3 = param_1->p;
    pBVar4 = param_1->q;
    if ((pBVar3 == (BIGNUM *)0x0) ||
       (((iVar1 = BN_get_flags(pBVar3,2), iVar1 != 0 && (iVar1 = BN_get_flags(pBVar3,1), iVar1 == 0)
         ) || (pBVar3 = BN_dup(pBVar3), pBVar3 != (BIGNUM *)0x0)))) {
      BN_clear_free(dh->p);
      dh->p = pBVar3;
      pBVar3 = param_1->g;
      if ((pBVar3 == (BIGNUM *)0x0) ||
         (((iVar1 = BN_get_flags(pBVar3,2), iVar1 != 0 &&
           (iVar1 = BN_get_flags(pBVar3,1), iVar1 == 0)) ||
          (pBVar3 = BN_dup(pBVar3), pBVar3 != (BIGNUM *)0x0)))) {
        BN_clear_free(dh->g);
        dh->g = pBVar3;
        if (pBVar4 == (BIGNUM *)0x0) {
          dh->length = param_1->length;
          return dh;
        }
        pBVar3 = param_1->q;
        if (((pBVar3 == (BIGNUM *)0x0) ||
            ((iVar1 = BN_get_flags(pBVar3,2), iVar1 != 0 &&
             (iVar1 = BN_get_flags(pBVar3,1), iVar1 == 0)))) ||
           (pBVar3 = BN_dup(pBVar3), pBVar3 != (BIGNUM *)0x0)) {
          BN_clear_free(dh->q);
          dh->q = pBVar3;
          pBVar3 = param_1->j;
          if ((pBVar3 == (BIGNUM *)0x0) ||
             (((iVar1 = BN_get_flags(pBVar3,2), iVar1 != 0 &&
               (iVar1 = BN_get_flags(pBVar3,1), iVar1 == 0)) ||
              (pBVar3 = BN_dup(pBVar3), pBVar3 != (BIGNUM *)0x0)))) {
            BN_clear_free(dh->j);
            dh->j = pBVar3;
            CRYPTO_free(dh->seed);
            dh->seed = (uchar *)0x0;
            puVar2 = param_1->seed;
            dh->seedlen = 0;
            if (puVar2 == (uchar *)0x0) {
              return dh;
            }
            puVar2 = (uchar *)CRYPTO_memdup(puVar2,param_1->seedlen,"crypto/dh/dh_ameth.c",0x19b);
            dh->seed = puVar2;
            if (puVar2 != (uchar *)0x0) {
              dh->seedlen = param_1->seedlen;
              return dh;
            }
          }
        }
      }
    }
    DH_free(dh);
  }
  return (DH *)0x0;
}

