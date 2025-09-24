
ASN1_OCTET_STRING * a2i_IPADDRESS_NC(char *ipasc)

{
  char *pcVar1;
  char *ipasc_00;
  int iVar2;
  int iVar3;
  ASN1_STRING *str;
  uint uVar4;
  uchar auStack_40 [36];
  
  pcVar1 = strchr(ipasc,0x2f);
  if ((pcVar1 != (char *)0x0) &&
     (ipasc_00 = CRYPTO_strdup(ipasc,"crypto/x509v3/v3_utl.c",0x410), ipasc_00 != (char *)0x0)) {
    ipasc_00[(int)pcVar1 - (int)ipasc] = '\0';
    iVar2 = a2i_ipadd(auStack_40,ipasc_00);
    if (iVar2 == 0) {
      str = (ASN1_STRING *)0x0;
    }
    else {
      iVar3 = a2i_ipadd(auStack_40 + iVar2,ipasc_00 + ((int)pcVar1 - (int)ipasc) + 1);
      CRYPTO_free(ipasc_00);
      uVar4 = iVar2 - iVar3;
      if (uVar4 != 0) {
        uVar4 = 1;
      }
      if (iVar3 == 0) {
        uVar4 = uVar4 | 1;
      }
      if ((uVar4 == 0) && (str = ASN1_OCTET_STRING_new(), str != (ASN1_OCTET_STRING *)0x0)) {
        ipasc_00 = (char *)ASN1_OCTET_STRING_set(str,auStack_40,iVar2 + iVar3);
        if (ipasc_00 != (char *)0x0) {
          return str;
        }
      }
      else {
        ipasc_00 = (char *)0x0;
        str = (ASN1_STRING *)0x0;
      }
    }
    CRYPTO_free(ipasc_00);
    ASN1_OCTET_STRING_free(str);
  }
  return (ASN1_OCTET_STRING *)0x0;
}

