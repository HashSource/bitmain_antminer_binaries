
int BN_nnmod(BIGNUM *r,BIGNUM *m,BIGNUM *d,BN_CTX *ctx)

{
  int iVar1;
  code *UNRECOVERED_JUMPTABLE;
  
  iVar1 = BN_div((BIGNUM *)0x0,r,m,d,ctx);
  if (iVar1 != 0) {
    if (r->neg != 0) {
      if (d->neg == 0) {
        UNRECOVERED_JUMPTABLE = (code *)0x1832ed;
      }
      else {
        UNRECOVERED_JUMPTABLE = (code *)0x183341;
      }
                    /* WARNING: Could not recover jumptable at 0x00187408. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      iVar1 = (*UNRECOVERED_JUMPTABLE)(r,r,d);
      return iVar1;
    }
    iVar1 = 1;
  }
  return iVar1;
}

