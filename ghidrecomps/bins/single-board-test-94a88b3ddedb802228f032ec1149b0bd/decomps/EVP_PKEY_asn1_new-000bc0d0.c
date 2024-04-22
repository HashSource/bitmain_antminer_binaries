
EVP_PKEY_ASN1_METHOD * EVP_PKEY_asn1_new(int id,int flags,char *pem_str,char *info)

{
  int *__s;
  char *pcVar1;
  
  __s = (int *)CRYPTO_malloc(0x6c,DAT_000bc17c,0x121);
  if (__s == (int *)0x0) {
    return (EVP_PKEY_ASN1_METHOD *)0x0;
  }
  memset(__s,0,0x6c);
  *__s = id;
  __s[2] = flags | 2;
  __s[1] = id;
  if (info == (char *)0x0) {
    __s[4] = 0;
  }
  else {
    pcVar1 = BUF_strdup(info);
    __s[4] = (int)pcVar1;
    if (pcVar1 == (char *)0x0) goto LAB_000bc15c;
  }
  if (pem_str == (char *)0x0) {
    __s[3] = 0;
  }
  else {
    pcVar1 = BUF_strdup(pem_str);
    __s[3] = (int)pcVar1;
    if (pcVar1 == (char *)0x0) {
LAB_000bc15c:
      if (-1 < __s[2] << 0x1e) {
        return (EVP_PKEY_ASN1_METHOD *)0x0;
      }
      if ((void *)__s[3] != (void *)0x0) {
        CRYPTO_free((void *)__s[3]);
      }
      if ((void *)__s[4] != (void *)0x0) {
        CRYPTO_free((void *)__s[4]);
      }
      CRYPTO_free(__s);
      return (EVP_PKEY_ASN1_METHOD *)0x0;
    }
  }
  __s[5] = 0;
  __s[6] = 0;
  __s[7] = 0;
  __s[8] = 0;
  __s[9] = 0;
  __s[10] = 0;
  __s[0xb] = 0;
  __s[0x18] = 0;
  __s[0x17] = 0;
  __s[0x19] = 0;
  __s[0x1a] = 0;
  __s[0xc] = 0;
  __s[0xd] = 0;
  __s[0xe] = 0;
  __s[0xf] = 0;
  __s[0x10] = 0;
  __s[0x11] = 0;
  __s[0x12] = 0;
  __s[0x13] = 0;
  __s[0x15] = 0;
  __s[0x16] = 0;
  return (EVP_PKEY_ASN1_METHOD *)__s;
}

