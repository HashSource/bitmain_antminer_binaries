
EVP_PKEY_ASN1_METHOD * ENGINE_get_pkey_asn1_meth_str(ENGINE *e,char *str,int len)

{
  EVP_PKEY_ASN1_METHOD *pEVar1;
  int iVar2;
  size_t sVar3;
  int iVar4;
  code *pcVar5;
  int iVar6;
  char *__s;
  int local_30;
  EVP_PKEY_ASN1_METHOD *local_2c [2];
  
  pcVar5 = *(code **)(e + 0x28);
  if (pcVar5 != (code *)0x0) {
    if (len == -1) {
      len = strlen(str);
    }
    iVar2 = (*pcVar5)(e,0,&local_30);
    if (0 < iVar2) {
      iVar6 = 0;
      do {
        iVar4 = iVar6 * 4;
        iVar6 = iVar6 + 1;
        (**(code **)(e + 0x28))(e,local_2c,0,*(undefined4 *)(local_30 + iVar4));
        pEVar1 = local_2c[0];
        if (local_2c[0] != (EVP_PKEY_ASN1_METHOD *)0x0) {
          __s = *(char **)(local_2c[0] + 0xc);
          sVar3 = strlen(__s);
          if ((len == sVar3) && (iVar4 = strncasecmp(__s,str,len), iVar4 == 0)) {
            return pEVar1;
          }
        }
      } while (iVar2 != iVar6);
    }
  }
  return (EVP_PKEY_ASN1_METHOD *)0x0;
}

