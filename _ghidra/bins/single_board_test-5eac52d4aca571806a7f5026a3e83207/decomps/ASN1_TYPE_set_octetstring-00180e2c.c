
int ASN1_TYPE_set_octetstring(ASN1_TYPE *a,uchar *data,int len)

{
  ASN1_OCTET_STRING *str;
  int iVar1;
  
  str = ASN1_OCTET_STRING_new();
  if (str == (ASN1_OCTET_STRING *)0x0) {
    return 0;
  }
  iVar1 = ASN1_OCTET_STRING_set(str,data,len);
  if (iVar1 != 0) {
    ASN1_TYPE_set(a,4,str);
    return 1;
  }
  ASN1_OCTET_STRING_free(str);
  return 0;
}

