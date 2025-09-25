
void * BN_GENCB_new(void)

{
  void *pvVar1;
  
  pvVar1 = CRYPTO_malloc(0xc,"crypto/bn/bn_lib.c",0x3b5);
  if (pvVar1 == (void *)0x0) {
    ERR_put_error(3,0x8f,0x41,"crypto/bn/bn_lib.c",0x3b6);
  }
  return pvVar1;
}

