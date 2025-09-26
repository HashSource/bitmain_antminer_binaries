
undefined4 x509_name_ex_new(undefined4 *param_1)

{
  int *ptr;
  int iVar1;
  BUF_MEM *pBVar2;
  
  ptr = (int *)CRYPTO_zalloc(0x14,"crypto/x509/x_name.c",0x5c);
  if (ptr == (int *)0x0) {
    ERR_put_error(0xd,0xab,0x41,"crypto/x509/x_name.c",0x69);
    return 0;
  }
  iVar1 = OPENSSL_sk_new_null();
  *ptr = iVar1;
  if (iVar1 != 0) {
    pBVar2 = BUF_MEM_new();
    ptr[2] = (int)pBVar2;
    if (pBVar2 != (BUF_MEM *)0x0) {
      ptr[1] = 1;
      *param_1 = ptr;
      return 1;
    }
  }
  ERR_put_error(0xd,0xab,0x41,"crypto/x509/x_name.c",0x69);
  OPENSSL_sk_free(*ptr);
  CRYPTO_free(ptr);
  return 0;
}

