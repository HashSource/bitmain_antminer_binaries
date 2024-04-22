
void cms_ias_cert_cmp(X509_NAME **param_1,X509 *param_2)

{
  X509_NAME *pXVar1;
  int iVar2;
  ASN1_INTEGER *y;
  X509_NAME *a;
  
  a = *param_1;
  pXVar1 = X509_get_issuer_name(param_2);
  iVar2 = X509_NAME_cmp(a,pXVar1);
  if (iVar2 != 0) {
    return;
  }
  pXVar1 = param_1[1];
  y = X509_get_serialNumber(param_2);
  ASN1_INTEGER_cmp((ASN1_INTEGER *)pXVar1,y);
  return;
}

