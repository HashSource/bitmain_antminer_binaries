
void engine_table_cleanup(undefined4 *param_1)

{
  CRYPTO_lock(9,0x1e,"eng_table.c",0xe5);
  if ((_LHASH *)*param_1 != (_LHASH *)0x0) {
    lh_doall((_LHASH *)*param_1,(LHASH_DOALL_FN_TYPE)0x19afb1);
    lh_free((_LHASH *)*param_1);
    *param_1 = 0;
  }
  CRYPTO_lock(10,0x1e,"eng_table.c",0xec);
  return;
}

