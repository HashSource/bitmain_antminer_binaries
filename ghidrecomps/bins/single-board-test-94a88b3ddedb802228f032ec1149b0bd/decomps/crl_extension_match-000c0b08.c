
int crl_extension_match(X509_CRL *param_1,X509_CRL *param_2,int param_3)

{
  int iVar1;
  int iVar2;
  ASN1_OCTET_STRING *b;
  X509_EXTENSION *pXVar3;
  ASN1_OCTET_STRING *a;
  uint uVar4;
  uint uVar5;
  
  iVar1 = X509_CRL_get_ext_by_NID(param_1,param_3,-1);
  if (iVar1 < 0) {
    a = (ASN1_STRING *)0x0;
  }
  else {
    iVar2 = X509_CRL_get_ext_by_NID(param_1,param_3,iVar1);
    if (iVar2 != -1) {
      return 0;
    }
    pXVar3 = X509_CRL_get_ext(param_1,iVar1);
    a = X509_EXTENSION_get_data(pXVar3);
  }
  iVar1 = X509_CRL_get_ext_by_NID(param_2,param_3,-1);
  if (iVar1 < 0) {
    uVar4 = 1;
    b = (ASN1_STRING *)0x0;
  }
  else {
    iVar2 = X509_CRL_get_ext_by_NID(param_2,param_3,iVar1);
    if (iVar2 != -1) {
      return 0;
    }
    pXVar3 = X509_CRL_get_ext(param_2,iVar1);
    b = X509_EXTENSION_get_data(pXVar3);
    uVar4 = 1 - (int)b;
    if ((ASN1_OCTET_STRING *)0x1 < b) {
      uVar4 = 0;
    }
  }
  uVar5 = 1 - (int)a;
  if ((ASN1_STRING *)0x1 < a) {
    uVar5 = 0;
  }
  if ((uVar4 & uVar5) == 0) {
    if ((uVar4 | uVar5) != 0) {
      return 0;
    }
    uVar4 = ASN1_OCTET_STRING_cmp(a,b);
    iVar1 = 1 - uVar4;
    if (1 < uVar4) {
      iVar1 = 0;
    }
    return iVar1;
  }
  return 1;
}

