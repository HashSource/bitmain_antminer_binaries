
void AUTHORITY_KEYID_free(AUTHORITY_KEYID *a)

{
  ASN1_item_free((ASN1_VALUE *)a,(ASN1_ITEM *)&AUTHORITY_KEYID_it);
  return;
}

