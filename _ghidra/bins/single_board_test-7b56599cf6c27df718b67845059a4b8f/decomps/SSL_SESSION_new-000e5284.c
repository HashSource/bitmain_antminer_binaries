
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

SSL_SESSION * SSL_SESSION_new(void)

{
  SSL_SESSION *ptr;
  time_t tVar1;
  int iVar2;
  
  ptr = (SSL_SESSION *)OPENSSL_init_ssl(0x200000,0,0);
  if (ptr != (SSL_SESSION *)0x0) {
    ptr = (SSL_SESSION *)CRYPTO_zalloc(0x204,"ssl/ssl_sess.c",0x48);
    if (ptr == (SSL_SESSION *)0x0) {
      ERR_put_error(0x14,0xbd,0x41,"ssl/ssl_sess.c",0x4a);
    }
    else {
      ptr->verify_result = 1;
      DataMemoryBarrier(0x1b);
      ptr->references = 1;
      DataMemoryBarrier(0x1b);
      ptr->timeout = 0x130;
      tVar1 = time((time_t *)0x0);
      ptr->time = tVar1;
      iVar2 = CRYPTO_THREAD_lock_new();
      *(int *)(ptr[1].key_arg + 4) = iVar2;
      if (iVar2 == 0) {
        ERR_put_error(0x14,0xbd,0x41,"ssl/ssl_sess.c",0x54);
        CRYPTO_free(ptr);
        ptr = (SSL_SESSION *)0x0;
      }
      else {
        iVar2 = CRYPTO_new_ex_data(2,ptr,(CRYPTO_EX_DATA *)&ptr->ciphers);
        if (iVar2 == 0) {
          CRYPTO_THREAD_lock_free(*(undefined4 *)(ptr[1].key_arg + 4));
          CRYPTO_free(ptr);
          ptr = (SSL_SESSION *)0x0;
        }
      }
    }
  }
  return ptr;
}

