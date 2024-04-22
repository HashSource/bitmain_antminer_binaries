
int X509_CRL_get0_by_cert(X509_CRL *crl,X509_REVOKED **ret,X509 *x)

{
  ASN1_INTEGER *pAVar1;
  X509_NAME *pXVar2;
  int iVar3;
  code *pcVar4;
  
  pcVar4 = *(code **)(crl->meth + 0xc);
  if (pcVar4 != (code *)0x0) {
    pAVar1 = X509_get_serialNumber(x);
    pXVar2 = X509_get_issuer_name(x);
    iVar3 = (*pcVar4)(crl,ret,pAVar1,pXVar2);
    return iVar3;
  }
  return 0;
}

