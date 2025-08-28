
void OCSP_ONEREQ_free(OCSP_ONEREQ *a)

{
  ASN1_item_free((ASN1_VALUE *)a,(ASN1_ITEM *)OCSP_ONEREQ_it);
  return;
}

