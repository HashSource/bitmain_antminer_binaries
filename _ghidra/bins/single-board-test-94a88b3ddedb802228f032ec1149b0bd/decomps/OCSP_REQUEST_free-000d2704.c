
void OCSP_REQUEST_free(OCSP_REQUEST *a)

{
  ASN1_item_free((ASN1_VALUE *)a,(ASN1_ITEM *)OCSP_REQUEST_it);
  return;
}

