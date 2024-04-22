
int X509_verify(X509 *a,EVP_PKEY *r)

{
  int iVar1;
  
  iVar1 = X509_ALGOR_cmp(a->sig_alg,a->cert_info->signature);
  if (iVar1 == 0) {
    iVar1 = ASN1_item_verify(DAT_000c43cc,a->sig_alg,a->signature,a->cert_info,r);
  }
  else {
    iVar1 = 0;
  }
  return iVar1;
}

