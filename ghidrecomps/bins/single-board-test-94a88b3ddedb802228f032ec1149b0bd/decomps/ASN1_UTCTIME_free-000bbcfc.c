
void ASN1_UTCTIME_free(ASN1_UTCTIME *a)

{
  ASN1_item_free((ASN1_VALUE *)a,(ASN1_ITEM *)ASN1_UTCTIME_it);
  return;
}

