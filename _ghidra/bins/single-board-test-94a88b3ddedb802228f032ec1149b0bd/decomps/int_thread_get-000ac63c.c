
_LHASH * int_thread_get(int param_1)

{
  _LHASH *p_Var1;
  
  CRYPTO_lock(9,1,"err.c",0x1c4);
  p_Var1 = int_thread_hash;
  if (int_thread_hash == (_LHASH *)0x0) {
    if (param_1 == 0) goto LAB_000ac65a;
    CRYPTO_push_info_("int_thread_get (err.c)","err.c",0x1c6);
    int_thread_hash = lh_new((LHASH_HASH_FN_TYPE)0xac70d,(LHASH_COMP_FN_TYPE)0xac709);
    CRYPTO_pop_info();
    if (int_thread_hash == (_LHASH *)0x0) goto LAB_000ac65a;
  }
  int_thread_hash_references = int_thread_hash_references + 1;
  p_Var1 = int_thread_hash;
LAB_000ac65a:
  CRYPTO_lock(10,1,"err.c",0x1ce);
  return p_Var1;
}

