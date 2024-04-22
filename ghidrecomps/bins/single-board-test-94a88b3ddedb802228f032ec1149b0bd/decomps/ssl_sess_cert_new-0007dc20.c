
void * ssl_sess_cert_new(void)

{
  void *__s;
  
  __s = CRYPTO_malloc(0xfc,DAT_0007dc64,0x27e);
  if (__s == (void *)0x0) {
    ERR_put_error(0x14,0xe1,0x41,DAT_0007dc64,0x280);
  }
  else {
    memset(__s,0,0xfc);
    *(int *)((int)__s + 8) = (int)__s + 0xc;
    *(undefined4 *)((int)__s + 0xf8) = 1;
  }
  return __s;
}

