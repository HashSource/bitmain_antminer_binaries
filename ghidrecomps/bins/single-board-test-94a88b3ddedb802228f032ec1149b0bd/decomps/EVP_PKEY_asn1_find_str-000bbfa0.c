
EVP_PKEY_ASN1_METHOD * EVP_PKEY_asn1_find_str(ENGINE **pe,char *str,int len)

{
  EVP_PKEY_ASN1_METHOD *pEVar1;
  int iVar2;
  size_t sVar3;
  int iVar4;
  char *__s;
  ENGINE *local_24;
  
  if (len == -1) {
    len = strlen(str);
  }
  if (pe != (ENGINE **)0x0) {
    pEVar1 = ENGINE_pkey_asn1_find_str(&local_24,str,len);
    if (pEVar1 != (EVP_PKEY_ASN1_METHOD *)0x0) {
      iVar2 = ENGINE_init(local_24);
      if (iVar2 == 0) {
        pEVar1 = (EVP_PKEY_ASN1_METHOD *)0x0;
      }
      ENGINE_free(local_24);
      *pe = local_24;
      return pEVar1;
    }
    *pe = (ENGINE *)0x0;
  }
  iVar2 = 0;
  do {
    if (app_methods == (_STACK *)0x0) {
      if (0xb < iVar2) {
        return (EVP_PKEY_ASN1_METHOD *)0x0;
      }
    }
    else {
      iVar4 = sk_num(app_methods);
      if (iVar4 + 0xc <= iVar2) {
        return (EVP_PKEY_ASN1_METHOD *)0x0;
      }
    }
    if (iVar2 < 0) {
      pEVar1 = (EVP_PKEY_ASN1_METHOD *)0x0;
    }
    else if (iVar2 < 0xc) {
      pEVar1 = (EVP_PKEY_ASN1_METHOD *)(&standard_methods)[iVar2];
    }
    else {
      pEVar1 = (EVP_PKEY_ASN1_METHOD *)sk_value(app_methods,iVar2 + -0xc);
    }
    if (-1 < *(int *)(pEVar1 + 8) << 0x1f) {
      __s = *(char **)(pEVar1 + 0xc);
      sVar3 = strlen(__s);
      if ((sVar3 == len) && (iVar4 = strncasecmp(__s,str,len), iVar4 == 0)) {
        return pEVar1;
      }
    }
    iVar2 = iVar2 + 1;
  } while( true );
}

