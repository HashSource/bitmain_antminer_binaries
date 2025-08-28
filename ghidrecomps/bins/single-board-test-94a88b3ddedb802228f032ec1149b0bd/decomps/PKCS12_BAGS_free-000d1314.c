
void PKCS12_BAGS_free(PKCS12_BAGS *a)

{
  ASN1_item_free((ASN1_VALUE *)a,(ASN1_ITEM *)PKCS12_BAGS_it);
  return;
}

