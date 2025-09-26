
void X509_REQ_free(X509_REQ *a)

{
  ASN1_item_free((ASN1_VALUE *)a,(ASN1_ITEM *)X509_REQ_it);
  return;
}

