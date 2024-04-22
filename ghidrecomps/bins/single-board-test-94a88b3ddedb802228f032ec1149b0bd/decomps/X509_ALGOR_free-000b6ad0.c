
void X509_ALGOR_free(X509_ALGOR *a)

{
  ASN1_item_free((ASN1_VALUE *)a,(ASN1_ITEM *)&X509_ALGOR_it);
  return;
}

