
int NETSCAPE_SPKI_verify(NETSCAPE_SPKI *a,EVP_PKEY *r)

{
  int iVar1;
  
  iVar1 = ASN1_item_verify((ASN1_ITEM *)NETSCAPE_SPKAC_it,(X509_ALGOR *)&a->sig_algor,
                           (ASN1_BIT_STRING *)a[1].spkac,a->spkac,r);
  return iVar1;
}

