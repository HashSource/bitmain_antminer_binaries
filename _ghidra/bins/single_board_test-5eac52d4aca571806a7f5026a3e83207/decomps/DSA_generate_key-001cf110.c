
int DSA_generate_key(DSA *a)

{
  int iVar1;
  BN_CTX *ctx;
  BIGNUM *p;
  code *UNRECOVERED_JUMPTABLE;
  BIGNUM *a_00;
  BIGNUM *r;
  
  UNRECOVERED_JUMPTABLE = (code *)(a->method_mont_p->Ni).d;
  if (UNRECOVERED_JUMPTABLE != (code *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x001cf116. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    iVar1 = (*UNRECOVERED_JUMPTABLE)();
    return iVar1;
  }
  ctx = BN_CTX_new();
  if ((ctx == (BN_CTX *)0x0) ||
     ((a_00 = a->pub_key, a_00 == (BIGNUM *)0x0 &&
      (a_00 = (BIGNUM *)BN_secure_new(), a_00 == (BIGNUM *)0x0)))) {
    r = (BIGNUM *)0x0;
    a_00 = r;
  }
  else {
    do {
      iVar1 = BN_priv_rand_range(a_00,a->p);
      if (iVar1 == 0) {
        r = (BIGNUM *)0x0;
        goto LAB_001cf146;
      }
      iVar1 = BN_is_zero(a_00);
    } while (iVar1 != 0);
    r = a->g;
    if (((r != (BIGNUM *)0x0) || (r = BN_new(), r != (BIGNUM *)0x0)) &&
       (p = BN_new(), p != (BIGNUM *)0x0)) {
      BN_with_flags(p,a_00,4);
      iVar1 = BN_mod_exp(r,a->q,p,(BIGNUM *)a->write_params,ctx);
      if (iVar1 != 0) {
        iVar1 = 1;
        BN_free(p);
        a->pub_key = a_00;
        a->g = r;
        goto LAB_001cf162;
      }
      BN_free(p);
    }
  }
LAB_001cf146:
  if (a->g != r) {
    BN_free(r);
  }
  if (a_00 == a->pub_key) {
    iVar1 = 0;
  }
  else {
    iVar1 = 0;
    BN_free(a_00);
  }
LAB_001cf162:
  BN_CTX_free(ctx);
  return iVar1;
}

