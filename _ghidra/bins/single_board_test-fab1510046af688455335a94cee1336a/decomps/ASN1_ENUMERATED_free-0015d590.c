
void ASN1_ENUMERATED_free(ASN1_ENUMERATED *a)

{
  ASN1_item_free((ASN1_VALUE *)a,(ASN1_ITEM *)ASN1_ENUMERATED_it);
  return;
}

