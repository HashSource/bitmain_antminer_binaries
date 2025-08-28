
void USERNOTICE_free(USERNOTICE *a)

{
  ASN1_item_free((ASN1_VALUE *)a,(ASN1_ITEM *)USERNOTICE_it);
  return;
}

