
_LHASH * int_err_get(int param_1)

{
  _LHASH *p_Var1;
  
  CRYPTO_lock(9,1,"err.c",0x168);
  if ((int_error_hash == (_LHASH *)0x0) && (param_1 != 0)) {
    CRYPTO_push_info_("int_err_get (err.c)","err.c",0x16a);
    int_error_hash = lh_new((LHASH_HASH_FN_TYPE)0x14fb91,(LHASH_COMP_FN_TYPE)0x14fbc9);
    CRYPTO_pop_info();
  }
  p_Var1 = int_error_hash;
  CRYPTO_lock(10,1,"err.c",0x170);
  return p_Var1;
}

