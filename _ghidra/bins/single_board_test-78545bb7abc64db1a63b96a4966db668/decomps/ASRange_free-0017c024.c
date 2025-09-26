
void ASRange_free(ASRange *a)

{
  ASN1_item_free((ASN1_VALUE *)a,(ASN1_ITEM *)ASRange_it);
  return;
}

