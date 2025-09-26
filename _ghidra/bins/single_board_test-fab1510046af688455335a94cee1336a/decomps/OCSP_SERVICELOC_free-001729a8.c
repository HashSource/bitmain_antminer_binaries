
void OCSP_SERVICELOC_free(OCSP_SERVICELOC *a)

{
  ASN1_item_free((ASN1_VALUE *)a,(ASN1_ITEM *)OCSP_SERVICELOC_it);
  return;
}

