
bool crl_extension_match(X509_CRL *param_1,X509_CRL *param_2,int param_3)

{
  int iVar1;
  int iVar2;
  ASN1_OCTET_STRING *b;
  X509_EXTENSION *pXVar3;
  ASN1_OCTET_STRING *a;
  
  iVar1 = X509_CRL_get_ext_by_NID(param_1,param_3,-1);
  if (iVar1 < 0) {
    iVar1 = X509_CRL_get_ext_by_NID(param_2,param_3,-1);
    if (iVar1 < 0) {
      return true;
    }
    a = (ASN1_STRING *)0x0;
  }
  else {
    iVar2 = X509_CRL_get_ext_by_NID(param_1,param_3,iVar1);
    if (iVar2 != -1) {
      return false;
    }
    pXVar3 = X509_CRL_get_ext(param_1,iVar1);
    a = X509_EXTENSION_get_data(pXVar3);
    iVar1 = X509_CRL_get_ext_by_NID(param_2,param_3,-1);
    if (iVar1 < 0) {
      if (a != (ASN1_OCTET_STRING *)0x0) {
        return false;
      }
      return true;
    }
  }
  iVar2 = X509_CRL_get_ext_by_NID(param_2,param_3,iVar1);
  if (iVar2 == -1) {
    pXVar3 = X509_CRL_get_ext(param_2,iVar1);
    b = X509_EXTENSION_get_data(pXVar3);
    if (a == (ASN1_STRING *)0x0 && b == (ASN1_OCTET_STRING *)0x0) {
      return true;
    }
    if (b != (ASN1_OCTET_STRING *)0x0 && a != (ASN1_STRING *)0x0) {
      iVar1 = ASN1_OCTET_STRING_cmp(a,b);
      return iVar1 == 0;
    }
  }
  return false;
}

