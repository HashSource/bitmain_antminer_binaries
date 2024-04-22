
void DSA_free(DSA *r)

{
  int iVar1;
  _func_1881 *p_Var2;
  
  if (r != (DSA *)0x0) {
    iVar1 = CRYPTO_add_lock(&r->references,-1,8,DAT_000fe424,0xc4);
    if (iVar1 < 1) {
      p_Var2 = r->meth->finish;
      if (p_Var2 != (_func_1881 *)0x0) {
        (*p_Var2)(r);
      }
      if (r->engine != (ENGINE *)0x0) {
        ENGINE_finish(r->engine);
      }
      CRYPTO_free_ex_data(7,r,&r->ex_data);
      if (r->p != (BIGNUM *)0x0) {
        BN_clear_free(r->p);
      }
      if (r->q != (BIGNUM *)0x0) {
        BN_clear_free(r->q);
      }
      if (r->g != (BIGNUM *)0x0) {
        BN_clear_free(r->g);
      }
      if (r->pub_key != (BIGNUM *)0x0) {
        BN_clear_free(r->pub_key);
      }
      if (r->priv_key != (BIGNUM *)0x0) {
        BN_clear_free(r->priv_key);
      }
      if (r->kinv != (BIGNUM *)0x0) {
        BN_clear_free(r->kinv);
      }
      if (r->r != (BIGNUM *)0x0) {
        BN_clear_free(r->r);
      }
      CRYPTO_free(r);
      return;
    }
  }
  return;
}

