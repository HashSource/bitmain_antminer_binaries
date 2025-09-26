
void SXNETID_free(SXNETID *a)

{
  ASN1_item_free((ASN1_VALUE *)a,(ASN1_ITEM *)&SXNETID_it);
  return;
}

