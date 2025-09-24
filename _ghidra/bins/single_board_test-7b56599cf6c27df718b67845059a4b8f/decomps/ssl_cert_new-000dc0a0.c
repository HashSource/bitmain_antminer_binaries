
int * ssl_cert_new(void)

{
  int *ptr;
  int iVar1;
  
  ptr = (int *)CRYPTO_zalloc(0x110,"ssl/ssl_cert.c",0x34);
  if (ptr == (int *)0x0) {
    ERR_put_error(0x14,0xa2,0x41,"ssl/ssl_cert.c",0x37);
  }
  else {
    *ptr = (int)(ptr + 5);
    DataMemoryBarrier(0x1b);
    ptr[0x42] = 1;
    DataMemoryBarrier(0x1b);
    ptr[0x3f] = 1;
    ptr[0x3e] = 0xdd1fd;
    ptr[0x40] = 0;
    iVar1 = CRYPTO_THREAD_lock_new();
    ptr[0x43] = iVar1;
    if (iVar1 == 0) {
      ERR_put_error(0x14,0xa2,0x41,"ssl/ssl_cert.c",0x42);
      CRYPTO_free(ptr);
      ptr = (int *)0x0;
    }
  }
  return ptr;
}

