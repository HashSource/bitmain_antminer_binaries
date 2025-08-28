
void OTHERNAME_free(OTHERNAME *a)

{
  ASN1_item_free((ASN1_VALUE *)a,(ASN1_ITEM *)OTHERNAME_it);
  return;
}

