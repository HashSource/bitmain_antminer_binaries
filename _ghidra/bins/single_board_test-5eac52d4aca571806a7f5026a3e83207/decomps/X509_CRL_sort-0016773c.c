
int X509_CRL_sort(X509_CRL *crl)

{
  int iVar1;
  int iVar2;
  
  OPENSSL_sk_sort(crl->idp);
  for (iVar2 = 0; iVar1 = OPENSSL_sk_num(crl->idp), iVar2 < iVar1; iVar2 = iVar2 + 1) {
    iVar1 = OPENSSL_sk_value(crl->idp,iVar2);
    *(int *)(iVar1 + 0x20) = iVar2;
  }
  crl->base_crl_number = (ASN1_INTEGER *)0x1;
  return 1;
}

