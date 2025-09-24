
void ASIdentifierChoice_free(ASIdentifierChoice *a)

{
  ASN1_item_free((ASN1_VALUE *)a,(ASN1_ITEM *)ASIdentifierChoice_it);
  return;
}

