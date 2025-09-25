
DH * DSA_dup_DH(DSA *r)

{
  DH *dh;
  BIGNUM *pBVar1;
  BIGNUM *pBVar2;
  BIGNUM *pBVar3;
  int iVar4;
  BIGNUM *pBVar5;
  BIGNUM *a;
  
  if ((r == (DSA *)0x0) || (dh = DH_new(), dh == (DH *)0x0)) {
    a = (BIGNUM *)0x0;
    dh = (DH *)0x0;
    pBVar2 = (BIGNUM *)0x0;
    pBVar1 = (BIGNUM *)0x0;
    pBVar5 = (BIGNUM *)0x0;
    pBVar3 = (BIGNUM *)0x0;
    goto LAB_00114866;
  }
  a = r->q;
  pBVar2 = a;
  pBVar1 = a;
  pBVar5 = a;
  pBVar3 = a;
  if ((BIGNUM *)r->write_params == (BIGNUM *)0x0) {
    if (a == (BIGNUM *)0x0) {
      if (r->p != (BIGNUM *)0x0) goto LAB_00114866;
      goto LAB_00114826;
    }
  }
  else {
    if ((a == (BIGNUM *)0x0) ||
       (a = r->p, pBVar2 = a, pBVar1 = a, pBVar5 = a, pBVar3 = a, a == (BIGNUM *)0x0))
    goto LAB_00114866;
    pBVar1 = BN_dup((BIGNUM *)r->write_params);
    pBVar2 = BN_dup(r->q);
    pBVar3 = BN_dup(r->p);
    if (pBVar2 == (BIGNUM *)0x0 || pBVar1 == (BIGNUM *)0x0) {
      a = (BIGNUM *)0x0;
      pBVar5 = (BIGNUM *)0x0;
      goto LAB_00114866;
    }
    if (pBVar3 == (BIGNUM *)0x0) {
      a = (BIGNUM *)0x0;
      pBVar5 = (BIGNUM *)0x0;
      goto LAB_00114866;
    }
    iVar4 = DH_set0_pqg(dh,pBVar1,pBVar3,pBVar2);
    if (iVar4 == 0) {
      a = (BIGNUM *)0x0;
      pBVar5 = (BIGNUM *)0x0;
      goto LAB_00114866;
    }
LAB_00114826:
    if (r->g != (BIGNUM *)0x0) {
      pBVar5 = BN_dup(r->g);
      if (pBVar5 == (BIGNUM *)0x0) {
        a = (BIGNUM *)0x0;
        pBVar2 = (BIGNUM *)0x0;
        pBVar1 = (BIGNUM *)0x0;
        pBVar3 = (BIGNUM *)0x0;
      }
      else {
        if (r->pub_key == (BIGNUM *)0x0) {
          a = (BIGNUM *)0x0;
        }
        else {
          a = BN_dup(r->pub_key);
          if (a == (BIGNUM *)0x0) {
            pBVar2 = (BIGNUM *)0x0;
            pBVar1 = (BIGNUM *)0x0;
            pBVar3 = (BIGNUM *)0x0;
            goto LAB_00114866;
          }
        }
        iVar4 = DH_set0_key(dh,pBVar5,a);
        if (iVar4 != 0) {
          return dh;
        }
        pBVar2 = (BIGNUM *)0x0;
        pBVar1 = (BIGNUM *)0x0;
        pBVar3 = (BIGNUM *)0x0;
      }
      goto LAB_00114866;
    }
    if (r->pub_key == (BIGNUM *)0x0) {
      return dh;
    }
  }
  a = (BIGNUM *)0x0;
  pBVar2 = a;
  pBVar1 = a;
  pBVar5 = a;
  pBVar3 = a;
LAB_00114866:
  BN_free(pBVar1);
  BN_free(pBVar2);
  BN_free(pBVar3);
  BN_free(pBVar5);
  BN_free(a);
  DH_free(dh);
  return (DH *)0x0;
}

