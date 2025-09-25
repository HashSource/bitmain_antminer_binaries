
EVP_PKEY_ASN1_METHOD * EVP_PKEY_asn1_find_str(ENGINE **pe,char *str,int len)

{
  EVP_PKEY_ASN1_METHOD *pEVar1;
  int iVar2;
  size_t sVar3;
  int iVar4;
  char *__s;
  ENGINE *local_1c;
  
  if (len == -1) {
    len = strlen(str);
  }
  if (pe != (ENGINE **)0x0) {
    pEVar1 = ENGINE_pkey_asn1_find_str(&local_1c,str,len);
    if (pEVar1 != (EVP_PKEY_ASN1_METHOD *)0x0) {
      iVar2 = ENGINE_init(local_1c);
      if (iVar2 == 0) {
        pEVar1 = (EVP_PKEY_ASN1_METHOD *)0x0;
      }
      ENGINE_free(local_1c);
      *pe = local_1c;
      return pEVar1;
    }
    *pe = (ENGINE *)0x0;
  }
  iVar2 = EVP_PKEY_asn1_get_count();
  do {
    do {
      iVar4 = iVar2 + -1;
      if (iVar2 < 1) {
        return (EVP_PKEY_ASN1_METHOD *)0x0;
      }
      pEVar1 = EVP_PKEY_asn1_get0(iVar4);
      iVar2 = iVar4;
    } while (*(int *)(pEVar1 + 8) << 0x1f < 0);
    __s = *(char **)(pEVar1 + 0xc);
    sVar3 = strlen(__s);
  } while ((len != sVar3) || (iVar4 = strncasecmp(__s,str,len), iVar4 != 0));
  return pEVar1;
}

