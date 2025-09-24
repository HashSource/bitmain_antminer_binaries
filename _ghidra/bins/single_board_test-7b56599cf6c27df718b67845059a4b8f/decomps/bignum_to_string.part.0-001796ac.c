
void * bignum_to_string_part_0(BIGNUM *param_1)

{
  char *__s;
  size_t sVar1;
  void *pvVar2;
  int num;
  
  __s = BN_bn2hex(param_1);
  if (__s == (char *)0x0) {
    pvVar2 = (void *)0x0;
  }
  else {
    sVar1 = strlen(__s);
    num = sVar1 + 3;
    pvVar2 = CRYPTO_malloc(num,"crypto/x509v3/v3_utl.c",0x94);
    if (pvVar2 == (void *)0x0) {
      ERR_put_error(0x22,0xa7,0x41,"crypto/x509v3/v3_utl.c",0x96);
      CRYPTO_free(__s);
    }
    else {
      if (*__s == '-') {
        OPENSSL_strlcpy(pvVar2,&DAT_002212e0,num);
        OPENSSL_strlcat(pvVar2,__s + 1,num);
      }
      else {
        OPENSSL_strlcpy(pvVar2,"0x",num);
        OPENSSL_strlcat(pvVar2,__s,num);
      }
      CRYPTO_free(__s);
    }
  }
  return pvVar2;
}

