
void X509_CERT_PAIR_free(X509_CERT_PAIR *a)

{
  ASN1_item_free((ASN1_VALUE *)a,DAT_000b7f44);
  return;
}

