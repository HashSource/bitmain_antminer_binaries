
void OCSP_RESPDATA_free(OCSP_RESPDATA *a)

{
  ASN1_item_free((ASN1_VALUE *)a,(ASN1_ITEM *)OCSP_RESPDATA_it);
  return;
}

