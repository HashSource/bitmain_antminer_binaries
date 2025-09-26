
void ASN1_BIT_STRING_free(ASN1_BIT_STRING *a)

{
  ASN1_item_free((ASN1_VALUE *)a,(ASN1_ITEM *)ASN1_BIT_STRING_it);
  return;
}

