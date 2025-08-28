
void ASN1_T61STRING_free(ASN1_T61STRING *a)

{
  ASN1_item_free((ASN1_VALUE *)a,(ASN1_ITEM *)ASN1_T61STRING_it);
  return;
}

