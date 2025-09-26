
void ASIdentifiers_free(ASIdentifiers *a)

{
  ASN1_item_free((ASN1_VALUE *)a,(ASN1_ITEM *)&ASIdentifiers_it);
  return;
}

