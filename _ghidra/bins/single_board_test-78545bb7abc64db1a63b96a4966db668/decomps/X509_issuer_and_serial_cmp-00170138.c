
int X509_issuer_and_serial_cmp(X509 *a,X509 *b)

{
  int iVar1;
  
  iVar1 = ASN1_INTEGER_cmp((ASN1_INTEGER *)&a->sig_alg,(ASN1_INTEGER *)&b->sig_alg);
  if (iVar1 != 0) {
    return iVar1;
  }
  iVar1 = X509_NAME_cmp((X509_NAME *)(a->ex_data).dummy,(X509_NAME *)(b->ex_data).dummy);
  return iVar1;
}

