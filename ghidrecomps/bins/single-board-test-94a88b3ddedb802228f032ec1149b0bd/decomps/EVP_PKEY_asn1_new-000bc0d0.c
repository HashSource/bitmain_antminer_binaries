
EVP_PKEY_ASN1_METHOD * EVP_PKEY_asn1_new(int id,int flags,char *pem_str,char *info)

{
  EVP_PKEY_ASN1_METHOD *__s;
  char *pcVar1;
  
  __s = (EVP_PKEY_ASN1_METHOD *)CRYPTO_malloc(0x6c,"ameth_lib.c",0x121);
  if (__s == (EVP_PKEY_ASN1_METHOD *)0x0) {
    return (EVP_PKEY_ASN1_METHOD *)0x0;
  }
  memset(__s,0,0x6c);
  *(int *)__s = id;
  *(uint *)(__s + 8) = flags | 2;
  *(int *)(__s + 4) = id;
  if (info == (char *)0x0) {
    *(int *)(__s + 0x10) = 0;
  }
  else {
    pcVar1 = BUF_strdup(info);
    *(char **)(__s + 0x10) = pcVar1;
    if (pcVar1 == (char *)0x0) goto LAB_000bc15c;
  }
  if (pem_str == (char *)0x0) {
    *(int *)(__s + 0xc) = 0;
  }
  else {
    pcVar1 = BUF_strdup(pem_str);
    *(char **)(__s + 0xc) = pcVar1;
    if (pcVar1 == (char *)0x0) {
LAB_000bc15c:
      if (-1 < *(int *)(__s + 8) << 0x1e) {
        return (EVP_PKEY_ASN1_METHOD *)0x0;
      }
      if (*(void **)(__s + 0xc) != (void *)0x0) {
        CRYPTO_free(*(void **)(__s + 0xc));
      }
      if (*(void **)(__s + 0x10) != (void *)0x0) {
        CRYPTO_free(*(void **)(__s + 0x10));
      }
      CRYPTO_free(__s);
      return (EVP_PKEY_ASN1_METHOD *)0x0;
    }
  }
  *(int *)(__s + 0x14) = 0;
  *(int *)(__s + 0x18) = 0;
  *(int *)(__s + 0x1c) = 0;
  *(int *)(__s + 0x20) = 0;
  *(int *)(__s + 0x24) = 0;
  *(int *)(__s + 0x28) = 0;
  *(int *)(__s + 0x2c) = 0;
  *(int *)(__s + 0x60) = 0;
  *(int *)(__s + 0x5c) = 0;
  *(int *)(__s + 100) = 0;
  *(int *)(__s + 0x68) = 0;
  *(int *)(__s + 0x30) = 0;
  *(int *)(__s + 0x34) = 0;
  *(int *)(__s + 0x38) = 0;
  *(int *)(__s + 0x3c) = 0;
  *(int *)(__s + 0x40) = 0;
  *(int *)(__s + 0x44) = 0;
  *(int *)(__s + 0x48) = 0;
  *(int *)(__s + 0x4c) = 0;
  *(int *)(__s + 0x54) = 0;
  *(int *)(__s + 0x58) = 0;
  return __s;
}

