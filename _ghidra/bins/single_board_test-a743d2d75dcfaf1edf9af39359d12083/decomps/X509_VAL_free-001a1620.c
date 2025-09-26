
void X509_VAL_free(X509_VAL *a)

{
  ASN1_item_free((ASN1_VALUE *)a,(ASN1_ITEM *)&X509_VAL_it);
  return;
}

