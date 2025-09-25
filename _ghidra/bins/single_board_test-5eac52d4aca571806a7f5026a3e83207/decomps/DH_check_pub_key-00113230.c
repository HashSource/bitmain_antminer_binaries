
int DH_check_pub_key(DH *dh,BIGNUM *pub_key,int *codes)

{
  BN_CTX *ctx;
  BIGNUM *a;
  int iVar1;
  BIGNUM *pBVar2;
  
  *codes = 0;
  ctx = BN_CTX_new();
  if (ctx != (BN_CTX *)0x0) {
    BN_CTX_start(ctx);
    a = BN_CTX_get(ctx);
    if ((a != (BIGNUM *)0x0) && (iVar1 = BN_set_word(a,1), iVar1 != 0)) {
      iVar1 = BN_cmp(pub_key,a);
      pBVar2 = dh->p;
      if (iVar1 < 1) {
        *codes = *codes | 1;
      }
      pBVar2 = BN_copy(a,pBVar2);
      if ((pBVar2 != (BIGNUM *)0x0) && (iVar1 = BN_sub_word(a,1), iVar1 != 0)) {
        iVar1 = BN_cmp(pub_key,a);
        pBVar2 = dh->q;
        if (-1 < iVar1) {
          *codes = *codes | 2;
        }
        if (pBVar2 != (BIGNUM *)0x0) {
          iVar1 = BN_mod_exp(a,pub_key,pBVar2,dh->p,ctx);
          if (iVar1 == 0) goto LAB_0011325e;
          iVar1 = BN_is_one(a);
          if (iVar1 == 0) {
            iVar1 = 1;
            *codes = *codes | 4;
            goto LAB_00113260;
          }
        }
        iVar1 = 1;
        goto LAB_00113260;
      }
    }
  }
LAB_0011325e:
  iVar1 = 0;
LAB_00113260:
  BN_CTX_end(ctx);
  BN_CTX_free(ctx);
  return iVar1;
}

