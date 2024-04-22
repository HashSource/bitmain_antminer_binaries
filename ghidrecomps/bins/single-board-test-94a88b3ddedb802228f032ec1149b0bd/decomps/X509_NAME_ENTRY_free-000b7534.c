
void X509_NAME_ENTRY_free(X509_NAME_ENTRY *a)

{
  ASN1_item_free((ASN1_VALUE *)a,(ASN1_ITEM *)&X509_NAME_ENTRY_it);
  return;
}

