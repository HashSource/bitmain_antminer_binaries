
void ASN1_IA5STRING_free(ASN1_IA5STRING *a)

{
  ASN1_item_free((ASN1_VALUE *)a,(ASN1_ITEM *)ASN1_IA5STRING_it);
  return;
}

