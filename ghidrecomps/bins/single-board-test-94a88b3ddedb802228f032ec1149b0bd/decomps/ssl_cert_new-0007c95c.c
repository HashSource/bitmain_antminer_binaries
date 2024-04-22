
int * ssl_cert_new(void)

{
  int *__s;
  EVP_MD *pEVar1;
  
  __s = (int *)CRYPTO_malloc(0x170,DAT_0007c9b8,0xcc);
  if (__s == (int *)0x0) {
    ERR_put_error(0x14,0xa2,0x41,DAT_0007c9b8,0xce);
  }
  else {
    memset(__s,0,0x170);
    *__s = (int)(__s + 0xf);
    __s[0x5b] = 1;
    pEVar1 = EVP_sha1();
    __s[0x1f] = (int)pEVar1;
    pEVar1 = EVP_sha1();
    __s[0x18] = (int)pEVar1;
    pEVar1 = EVP_sha1();
    __s[0x11] = (int)pEVar1;
    pEVar1 = EVP_sha1();
    __s[0x34] = (int)pEVar1;
  }
  return __s;
}

