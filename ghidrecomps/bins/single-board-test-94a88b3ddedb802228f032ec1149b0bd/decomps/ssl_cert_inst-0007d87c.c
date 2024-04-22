
undefined4 ssl_cert_inst(int **param_1)

{
  int *__s;
  EVP_MD *pEVar1;
  undefined4 uVar2;
  
  if (param_1 == (int **)0x0) {
    ERR_put_error(0x14,0xde,0x43,DAT_0007d918,0x20c);
    uVar2 = 0;
  }
  else {
    uVar2 = 1;
    if (*param_1 == (int *)0x0) {
      __s = (int *)CRYPTO_malloc(0x170,DAT_0007d918,0xcc);
      if (__s == (int *)0x0) {
        ERR_put_error(0x14,0xa2,0x41,DAT_0007d918,0xce);
        *param_1 = (int *)0x0;
        ERR_put_error(0x14,0xde,0x41,DAT_0007d918,0x211);
        uVar2 = 0;
      }
      else {
        memset(__s,0,0x170);
        uVar2 = 1;
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
        *param_1 = __s;
      }
    }
  }
  return uVar2;
}

