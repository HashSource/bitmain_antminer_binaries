
void OCSP_SIGNATURE_free(OCSP_SIGNATURE *a)

{
  ASN1_item_free((ASN1_VALUE *)a,(ASN1_ITEM *)&OCSP_SIGNATURE_it);
  return;
}

