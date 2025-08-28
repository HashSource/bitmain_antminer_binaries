
void ASN1_BMPSTRING_free(ASN1_BMPSTRING *a)

{
  ASN1_item_free((ASN1_VALUE *)a,(ASN1_ITEM *)ASN1_BMPSTRING_it);
  return;
}

