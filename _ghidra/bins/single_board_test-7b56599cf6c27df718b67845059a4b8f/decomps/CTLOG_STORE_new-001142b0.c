
int * CTLOG_STORE_new(void)

{
  int *ptr;
  int iVar1;
  
  ptr = (int *)CRYPTO_zalloc(4,"crypto/ct/ct_log.c",0x5e);
  if (ptr == (int *)0x0) {
    ERR_put_error(0x32,0x83,0x41,"crypto/ct/ct_log.c",0x61);
  }
  else {
    iVar1 = OPENSSL_sk_new_null();
    *ptr = iVar1;
    if (iVar1 == 0) {
      CRYPTO_free(ptr);
      ptr = (int *)0x0;
    }
  }
  return ptr;
}

