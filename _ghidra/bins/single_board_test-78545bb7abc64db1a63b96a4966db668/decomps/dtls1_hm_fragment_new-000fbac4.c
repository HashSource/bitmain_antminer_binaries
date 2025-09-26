
void * dtls1_hm_fragment_new(void *param_1,int param_2)

{
  void *ptr;
  void *ptr_00;
  
  ptr = CRYPTO_malloc(0x34,"ssl/statem/statem_dtls.c",0x3e);
  if (ptr == (void *)0x0) {
    ERR_put_error(0x14,0x26f,0x41,"ssl/statem/statem_dtls.c",0x3f);
  }
  else {
    ptr_00 = param_1;
    if ((param_1 == (void *)0x0) ||
       (ptr_00 = CRYPTO_malloc((int)param_1,"ssl/statem/statem_dtls.c",0x44), ptr_00 != (void *)0x0)
       ) {
      *(void **)((int)ptr + 0x2c) = ptr_00;
      if ((param_2 == 0) ||
         (param_2 = CRYPTO_zalloc((int)param_1 + 7U >> 3,"ssl/statem/statem_dtls.c",0x50),
         param_2 != 0)) {
        *(int *)((int)ptr + 0x30) = param_2;
      }
      else {
        ERR_put_error(0x14,0x26f,0x41,"ssl/statem/statem_dtls.c",0x52);
        CRYPTO_free(ptr_00);
        CRYPTO_free(ptr);
        ptr = (void *)0x0;
      }
    }
    else {
      ERR_put_error(0x14,0x26f,0x41,"ssl/statem/statem_dtls.c",0x45);
      CRYPTO_free(ptr);
      ptr = (void *)0x0;
    }
  }
  return ptr;
}

