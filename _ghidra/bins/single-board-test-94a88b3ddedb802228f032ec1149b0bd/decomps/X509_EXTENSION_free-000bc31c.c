
void X509_EXTENSION_free(X509_EXTENSION *a)

{
  ASN1_item_free((ASN1_VALUE *)a,(ASN1_ITEM *)&X509_EXTENSION_it);
  return;
}

