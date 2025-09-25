
void X509_PUBKEY_free(X509_PUBKEY *a)

{
  ASN1_item_free((ASN1_VALUE *)a,(ASN1_ITEM *)&X509_PUBKEY_it);
  return;
}

