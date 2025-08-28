
void OCSP_CRLID_free(OCSP_CRLID *a)

{
  ASN1_item_free((ASN1_VALUE *)a,(ASN1_ITEM *)OCSP_CRLID_it);
  return;
}

