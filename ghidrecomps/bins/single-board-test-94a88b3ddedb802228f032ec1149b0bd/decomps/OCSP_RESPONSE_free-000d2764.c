
void OCSP_RESPONSE_free(OCSP_RESPONSE *a)

{
  ASN1_item_free((ASN1_VALUE *)a,(ASN1_ITEM *)OCSP_RESPONSE_it);
  return;
}

