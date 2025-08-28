
void POLICYQUALINFO_free(POLICYQUALINFO *a)

{
  ASN1_item_free((ASN1_VALUE *)a,(ASN1_ITEM *)POLICYQUALINFO_it);
  return;
}

