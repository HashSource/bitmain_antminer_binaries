
int BN_mod_lshift_quick(BIGNUM *r,BIGNUM *a,int n,BIGNUM *m)

{
  BIGNUM *pBVar1;
  int iVar2;
  int iVar3;
  
  if (r == a) goto LAB_000f2090;
  pBVar1 = BN_copy(r,a);
  do {
    if (pBVar1 == (BIGNUM *)0x0) {
      return 0;
    }
LAB_000f2090:
    do {
      if (n < 1) {
        return 1;
      }
      iVar2 = BN_num_bits(m);
      iVar3 = BN_num_bits(r);
      iVar2 = iVar2 - iVar3;
      if (iVar2 < 0) {
        ERR_put_error(3,0x77,0x6e,DAT_000f2104,0x121);
        return 0;
      }
      iVar3 = n;
      if ((n < iVar2) || (iVar3 = iVar2, iVar2 != 0)) {
        iVar2 = BN_lshift(r,r,iVar3);
        if (iVar2 == 0) {
          return 0;
        }
        n = n - iVar3;
      }
      else {
        iVar2 = BN_lshift1(r,r);
        if (iVar2 == 0) {
          return 0;
        }
        n = n + -1;
      }
      iVar2 = BN_cmp(r,m);
    } while (iVar2 < 0);
    pBVar1 = (BIGNUM *)BN_sub(r,r,m);
  } while( true );
}

