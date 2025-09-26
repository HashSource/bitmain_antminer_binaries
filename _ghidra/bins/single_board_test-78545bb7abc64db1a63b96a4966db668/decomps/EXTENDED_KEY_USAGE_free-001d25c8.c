
void EXTENDED_KEY_USAGE_free(EXTENDED_KEY_USAGE *a)

{
  ASN1_item_free((ASN1_VALUE *)a,(ASN1_ITEM *)&EXTENDED_KEY_USAGE_it);
  return;
}

