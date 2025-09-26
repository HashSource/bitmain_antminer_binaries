
void int_cleanup(void)

{
  if (ex_data == (_LHASH *)0x0) {
    CRYPTO_lock(9,2,"ex_data.c",0x116);
    if (ex_data == (_LHASH *)0x0) {
      ex_data = lh_new((LHASH_HASH_FN_TYPE)0x133d59,(LHASH_COMP_FN_TYPE)0x133d5d);
      if (ex_data == (_LHASH *)0x0) {
        CRYPTO_lock(10,2,"ex_data.c",0x119);
        return;
      }
    }
    CRYPTO_lock(10,2,"ex_data.c",0x119);
  }
  lh_doall(ex_data,(LHASH_DOALL_FN_TYPE)0x133e15);
  lh_free(ex_data);
  ex_data = (_LHASH *)0x0;
  impl = 0;
  return;
}

