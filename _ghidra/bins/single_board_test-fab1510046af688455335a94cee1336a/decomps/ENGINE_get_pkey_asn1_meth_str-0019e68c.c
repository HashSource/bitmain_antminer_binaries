
EVP_PKEY_ASN1_METHOD * ENGINE_get_pkey_asn1_meth_str(ENGINE *e,char *str,int len)

{
  EVP_PKEY_ASN1_METHOD *pEVar1;
  int iVar2;
  size_t sVar3;
  int iVar4;
  code *pcVar5;
  int iVar6;
  char *__s;
  int local_28;
  EVP_PKEY_ASN1_METHOD *local_24;
  
  pcVar5 = *(code **)(e + 0x30);
  if (pcVar5 != (code *)0x0) {
    if (len == -1) {
      len = strlen(str);
    }
    iVar2 = (*pcVar5)(e,0,&local_28,0);
    if (0 < iVar2) {
      iVar6 = 0;
      do {
        iVar4 = iVar6 * 4;
        iVar6 = iVar6 + 1;
        (**(code **)(e + 0x30))(e,&local_24,0,*(undefined4 *)(local_28 + iVar4));
        pEVar1 = local_24;
        __s = *(char **)(local_24 + 0xc);
        sVar3 = strlen(__s);
        if ((sVar3 == len) && (iVar4 = strncasecmp(__s,str,len), iVar4 == 0)) {
          return pEVar1;
        }
      } while (iVar6 != iVar2);
    }
  }
  return (EVP_PKEY_ASN1_METHOD *)0x0;
}

