
void POLICY_MAPPING_free(POLICY_MAPPING *a)

{
  ASN1_item_free((ASN1_VALUE *)a,(ASN1_ITEM *)&POLICY_MAPPING_it);
  return;
}

