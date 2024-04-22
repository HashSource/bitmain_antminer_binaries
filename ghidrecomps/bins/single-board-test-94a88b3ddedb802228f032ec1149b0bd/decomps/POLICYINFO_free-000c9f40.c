
void POLICYINFO_free(POLICYINFO *a)

{
  ASN1_item_free((ASN1_VALUE *)a,(ASN1_ITEM *)&POLICYINFO_it);
  return;
}

