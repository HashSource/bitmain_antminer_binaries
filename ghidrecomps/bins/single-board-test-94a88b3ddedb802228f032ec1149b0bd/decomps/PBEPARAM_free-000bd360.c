
void PBEPARAM_free(PBEPARAM *a)

{
  ASN1_item_free((ASN1_VALUE *)a,(ASN1_ITEM *)&PBEPARAM_it);
  return;
}

