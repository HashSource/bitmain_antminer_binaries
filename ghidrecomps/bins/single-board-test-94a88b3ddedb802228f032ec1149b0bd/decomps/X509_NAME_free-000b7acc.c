
void X509_NAME_free(X509_NAME *a)

{
  ASN1_item_free((ASN1_VALUE *)a,(ASN1_ITEM *)X509_NAME_it);
  return;
}

