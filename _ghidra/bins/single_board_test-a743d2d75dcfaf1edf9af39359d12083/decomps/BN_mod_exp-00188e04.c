
int BN_mod_exp(BIGNUM *r,BIGNUM *a,BIGNUM *p,BIGNUM *m,BN_CTX *ctx)

{
  int iVar1;
  
  if ((0 < m->top) && ((*m->d & 1) != 0)) {
    if (((a->top == 1) && (a->neg == 0)) && ((p->flags & 4U) == 0)) {
      iVar1 = BN_mod_exp_mont_word(r,*a->d,p,m,ctx,(BN_MONT_CTX *)0x0);
    }
    else {
      iVar1 = BN_mod_exp_mont(r,a,p,m,ctx,(BN_MONT_CTX *)0x0);
    }
    return iVar1;
  }
  iVar1 = BN_mod_exp_recp(r,a,p,m,ctx);
  return iVar1;
}

