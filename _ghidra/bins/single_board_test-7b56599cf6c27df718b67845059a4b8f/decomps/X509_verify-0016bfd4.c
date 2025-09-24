
int X509_verify(X509 *a,EVP_PKEY *r)

{
  int iVar1;
  
  iVar1 = X509_ALGOR_cmp((X509_ALGOR *)&a->altname,(X509_ALGOR *)&a->name);
  if (iVar1 != 0) {
    return 0;
  }
  iVar1 = ASN1_item_verify((ASN1_ITEM *)X509_CINF_it,(X509_ALGOR *)&a->altname,
                           (ASN1_BIT_STRING *)&a->rfc3779_addr,a,r);
  return iVar1;
}

