
void int_err_del(void)

{
  CRYPTO_lock(9,1,"err.c",0x177);
  if (int_error_hash != (_LHASH *)0x0) {
    lh_free(int_error_hash);
    int_error_hash = (_LHASH *)0x0;
  }
  CRYPTO_lock(10,1,"err.c",0x17c);
  return;
}

