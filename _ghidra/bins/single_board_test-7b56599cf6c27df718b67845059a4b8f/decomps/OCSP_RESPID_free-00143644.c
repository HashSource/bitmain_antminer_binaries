
void OCSP_RESPID_free(OCSP_RESPID *a)

{
  ASN1_item_free((ASN1_VALUE *)a,(ASN1_ITEM *)OCSP_RESPID_it);
  return;
}

