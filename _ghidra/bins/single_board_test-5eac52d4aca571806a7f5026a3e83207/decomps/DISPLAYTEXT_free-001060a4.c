
void DISPLAYTEXT_free(ASN1_STRING *a)

{
  ASN1_item_free((ASN1_VALUE *)a,(ASN1_ITEM *)DISPLAYTEXT_it);
  return;
}

