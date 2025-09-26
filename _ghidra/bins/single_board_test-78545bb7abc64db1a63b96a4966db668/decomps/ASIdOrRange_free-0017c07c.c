
void ASIdOrRange_free(ASIdOrRange *a)

{
  ASN1_item_free((ASN1_VALUE *)a,(ASN1_ITEM *)ASIdOrRange_it);
  return;
}

