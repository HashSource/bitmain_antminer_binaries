
int SSL_COMP_add_compression_method(int id,COMP_METHOD *cm)

{
  int iVar1;
  int *ptr;
  
  if (cm == (COMP_METHOD *)0x0) {
    return 1;
  }
  iVar1 = COMP_get_type(cm);
  if (iVar1 != 0) {
    if (id - 0xc1U < 0x3f) {
      CRYPTO_mem_ctrl(3);
      ptr = (int *)CRYPTO_malloc(0xc,"ssl/ssl_ciph.c",0x7be);
      if (ptr == (int *)0x0) {
        CRYPTO_mem_ctrl(2);
        iVar1 = 0x7c1;
      }
      else {
        *ptr = id;
        ptr[2] = (int)cm;
        CRYPTO_THREAD_run_once(&ssl_load_builtin_comp_once,0xd91cd);
        if (ssl_comp_methods != 0) {
          iVar1 = OPENSSL_sk_find(ssl_comp_methods,ptr);
          if (-1 < iVar1) {
            CRYPTO_free(ptr);
            CRYPTO_mem_ctrl(2);
            ERR_put_error(0x14,0xa5,0x135,"ssl/ssl_ciph.c",0x7cc);
            return 1;
          }
          if ((ssl_comp_methods != 0) && (iVar1 = OPENSSL_sk_push(ssl_comp_methods,ptr), iVar1 != 0)
             ) {
            CRYPTO_mem_ctrl(2);
            return 0;
          }
        }
        CRYPTO_free(ptr);
        CRYPTO_mem_ctrl(2);
        iVar1 = 0x7d2;
      }
      ERR_put_error(0x14,0xa5,0x41,"ssl/ssl_ciph.c",iVar1);
      return 1;
    }
    ERR_put_error(0x14,0xa5,0x133,"ssl/ssl_ciph.c",0x7b9);
  }
  return 1;
}

