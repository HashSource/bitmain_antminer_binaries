
void GENERAL_NAME_free(GENERAL_NAME *a)

{
  ASN1_item_free((ASN1_VALUE *)a,(ASN1_ITEM *)&GENERAL_NAME_it);
  return;
}

