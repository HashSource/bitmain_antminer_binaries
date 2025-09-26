
void ASN1_INTEGER_free(ASN1_INTEGER *a)

{
  ASN1_item_free((ASN1_VALUE *)a,(ASN1_ITEM *)&ASN1_INTEGER_it);
  return;
}

