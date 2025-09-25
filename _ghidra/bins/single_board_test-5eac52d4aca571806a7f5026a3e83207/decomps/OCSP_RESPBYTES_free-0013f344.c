
void OCSP_RESPBYTES_free(OCSP_RESPBYTES *a)

{
  ASN1_item_free((ASN1_VALUE *)a,(ASN1_ITEM *)OCSP_RESPBYTES_it);
  return;
}

