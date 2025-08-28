
void ASN1_OCTET_STRING_free(ASN1_OCTET_STRING *a)

{
  ASN1_item_free((ASN1_VALUE *)a,(ASN1_ITEM *)ASN1_OCTET_STRING_it);
  return;
}

