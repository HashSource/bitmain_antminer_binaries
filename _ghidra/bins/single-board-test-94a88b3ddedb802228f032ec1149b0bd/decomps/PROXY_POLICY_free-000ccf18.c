
void PROXY_POLICY_free(PROXY_POLICY *a)

{
  ASN1_item_free((ASN1_VALUE *)a,(ASN1_ITEM *)&PROXY_POLICY_it);
  return;
}

