
void X509_SIG_free(X509_SIG *a)

{
  ASN1_item_free((ASN1_VALUE *)a,(ASN1_ITEM *)&X509_SIG_it);
  return;
}

