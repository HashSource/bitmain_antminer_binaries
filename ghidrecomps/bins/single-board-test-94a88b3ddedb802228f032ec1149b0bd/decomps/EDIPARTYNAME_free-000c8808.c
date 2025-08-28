
void EDIPARTYNAME_free(EDIPARTYNAME *a)

{
  ASN1_item_free((ASN1_VALUE *)a,(ASN1_ITEM *)EDIPARTYNAME_it);
  return;
}

