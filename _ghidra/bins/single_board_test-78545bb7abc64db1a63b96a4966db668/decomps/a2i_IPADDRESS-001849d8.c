
ASN1_OCTET_STRING * a2i_IPADDRESS(char *ipasc)

{
  int iVar1;
  ASN1_OCTET_STRING *str;
  uchar auStack_20 [16];
  
  iVar1 = a2i_ipadd(auStack_20,ipasc);
  if ((iVar1 != 0) && (str = ASN1_OCTET_STRING_new(), str != (ASN1_OCTET_STRING *)0x0)) {
    iVar1 = ASN1_OCTET_STRING_set(str,auStack_20,iVar1);
    if (iVar1 == 0) {
      ASN1_OCTET_STRING_free(str);
      str = (ASN1_OCTET_STRING *)0x0;
    }
    return str;
  }
  return (ASN1_OCTET_STRING *)0x0;
}

