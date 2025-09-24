
void ASN1_TIME_free(ASN1_TIME *a)

{
  ASN1_item_free((ASN1_VALUE *)a,(ASN1_ITEM *)&ASN1_TIME_it);
  return;
}

