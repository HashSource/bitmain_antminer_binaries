
void X509_CRL_INFO_free(X509_CRL_INFO *a)

{
  ASN1_item_free((ASN1_VALUE *)a,(ASN1_ITEM *)&X509_CRL_INFO_it);
  return;
}

