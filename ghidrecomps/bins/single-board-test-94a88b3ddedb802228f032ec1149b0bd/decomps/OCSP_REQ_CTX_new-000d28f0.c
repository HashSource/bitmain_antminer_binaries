
undefined4 * OCSP_REQ_CTX_new(undefined4 param_1,int param_2)

{
  undefined4 *ptr;
  BIO_METHOD *type;
  BIO *pBVar1;
  void *ptr_00;
  
  ptr = (undefined4 *)CRYPTO_malloc(0x1c,DAT_000d2958,0x78);
  if (ptr == (undefined4 *)0x0) {
    return (undefined4 *)0x0;
  }
  *ptr = 0x1000;
  if (param_2 < 1) {
    param_2 = 0x1000;
  }
  ptr[6] = 0x19000;
  type = BIO_s_mem();
  pBVar1 = BIO_new(type);
  ptr[4] = pBVar1;
  ptr[2] = param_2;
  ptr[3] = param_1;
  ptr[5] = 0;
  ptr_00 = CRYPTO_malloc(param_2,DAT_000d2958,0x84);
  ptr[1] = ptr_00;
  if (ptr_00 == (void *)0x0) {
    if ((BIO *)ptr[4] == (BIO *)0x0) goto LAB_000d294e;
    BIO_free((BIO *)ptr[4]);
    ptr_00 = (void *)ptr[1];
    if (ptr_00 == (void *)0x0) goto LAB_000d294e;
  }
  else if (ptr[4] != 0) {
    return ptr;
  }
  CRYPTO_free(ptr_00);
LAB_000d294e:
  CRYPTO_free(ptr);
  return (undefined4 *)0x0;
}

