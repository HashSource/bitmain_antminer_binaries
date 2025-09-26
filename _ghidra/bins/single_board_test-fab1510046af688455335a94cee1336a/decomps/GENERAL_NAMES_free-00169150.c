
void GENERAL_NAMES_free(GENERAL_NAMES *a)

{
  ASN1_item_free((ASN1_VALUE *)a,(ASN1_ITEM *)GENERAL_NAMES_it);
  return;
}

