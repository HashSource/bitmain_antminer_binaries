
int DH_check(DH *dh,int *codes)

{
  BN_CTX *ctx;
  BIGNUM *r;
  BIGNUM *pBVar1;
  BIGNUM *b;
  int iVar2;
  ulong uVar3;
  BIGNUM *a;
  
  *codes = 0;
  ctx = BN_CTX_new();
  if (ctx == (BN_CTX *)0x0) {
    return 0;
  }
  BN_CTX_start(ctx);
  r = BN_CTX_get(ctx);
  if ((r == (BIGNUM *)0x0) || (pBVar1 = BN_CTX_get(ctx), pBVar1 == (BIGNUM *)0x0)) {
LAB_0014ac3a:
    iVar2 = 0;
  }
  else {
    if (dh->q == (BIGNUM *)0x0) {
      pBVar1 = dh->g;
      if (pBVar1->top == 1) {
        if (*pBVar1->d == 2) {
          if (pBVar1->neg != 0) goto LAB_0014ac66;
          uVar3 = BN_mod_word(dh->p,0x18);
          if (uVar3 != 0xb) goto LAB_0014acd8;
        }
        else {
          if ((*pBVar1->d != 5) || (pBVar1->neg != 0)) goto LAB_0014ac66;
          uVar3 = BN_mod_word(dh->p,10);
          if ((uVar3 & 0xfffffffb) != 3) {
LAB_0014acd8:
            *codes = *codes | 8;
          }
        }
      }
      else {
LAB_0014ac66:
        *codes = *codes | 4;
      }
    }
    else {
      a = dh->g;
      b = BN_value_one();
      iVar2 = BN_cmp(a,b);
      if ((iVar2 < 1) || (iVar2 = BN_cmp(dh->g,dh->p), -1 < iVar2)) {
LAB_0014abd6:
        *codes = *codes | 8;
      }
      else {
        iVar2 = BN_mod_exp(r,dh->g,dh->q,dh->p,ctx);
        if (iVar2 == 0) goto LAB_0014ac3a;
        if (((r->top != 1) || (*r->d != 1)) || (r->neg != 0)) goto LAB_0014abd6;
      }
      iVar2 = BN_is_prime_ex(dh->q,0,ctx,0);
      if (iVar2 == 0) {
        *codes = *codes | 0x10;
      }
      iVar2 = BN_div(r,pBVar1,dh->p,dh->q,ctx);
      if (iVar2 == 0) goto LAB_0014ac3a;
      if (((pBVar1->top != 1) || (*pBVar1->d != 1)) || (pBVar1->neg != 0)) {
        *codes = *codes | 0x20;
      }
      if ((dh->j != (BIGNUM *)0x0) && (iVar2 = BN_cmp(dh->j,r), iVar2 != 0)) {
        *codes = *codes | 0x40;
      }
    }
    iVar2 = BN_is_prime_ex(dh->p,0,ctx,0);
    if (iVar2 == 0) {
      iVar2 = 1;
      *codes = *codes | 1;
      goto LAB_0014ac3c;
    }
    if (dh->q == (BIGNUM *)0x0) {
      iVar2 = BN_rshift1(r,dh->p);
      if (iVar2 == 0) goto LAB_0014ac3a;
      iVar2 = BN_is_prime_ex(r,0,ctx);
      if (iVar2 == 0) {
        iVar2 = 1;
        *codes = *codes | 2;
        goto LAB_0014ac3c;
      }
    }
    iVar2 = 1;
  }
LAB_0014ac3c:
  BN_CTX_end(ctx);
  BN_CTX_free(ctx);
  return iVar2;
}

