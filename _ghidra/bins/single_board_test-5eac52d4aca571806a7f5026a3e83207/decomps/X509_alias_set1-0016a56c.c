
int X509_alias_set1(X509 *x,uchar *name,int len)

{
  int iVar1;
  ASN1_STRING *a;
  ASN1_UTF8STRING *str;
  X509_CERT_AUX *pXVar2;
  
  if (name == (uchar *)0x0) {
    if (((x != (X509 *)0x0) && (x[1].rfc3779_asid != (ASIdentifiers_st *)0x0)) &&
       (a = (ASN1_STRING *)x[1].rfc3779_asid[1].asnum, a != (ASN1_STRING *)0x0)) {
      ASN1_UTF8STRING_free(a);
      x[1].rfc3779_asid[1].asnum = (ASIdentifierChoice *)0x0;
    }
    return 1;
  }
  if (x != (X509 *)0x0) {
    pXVar2 = (X509_CERT_AUX *)x[1].rfc3779_asid;
    if (pXVar2 == (X509_CERT_AUX *)0x0) {
      pXVar2 = X509_CERT_AUX_new();
      x[1].rfc3779_asid = (ASIdentifiers_st *)pXVar2;
      if (pXVar2 == (X509_CERT_AUX *)0x0) {
        return 0;
      }
    }
    if (pXVar2->alias != (ASN1_STRING *)0x0) {
      iVar1 = ASN1_STRING_set(pXVar2->alias,name,len);
      return iVar1;
    }
    str = ASN1_UTF8STRING_new();
    pXVar2->alias = str;
    if (str != (ASN1_UTF8STRING *)0x0) {
      iVar1 = ASN1_STRING_set(str,name,len);
      return iVar1;
    }
  }
  return 0;
}

