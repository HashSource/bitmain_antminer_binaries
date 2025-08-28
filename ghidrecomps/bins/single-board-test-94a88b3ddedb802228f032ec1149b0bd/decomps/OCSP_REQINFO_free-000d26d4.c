
void OCSP_REQINFO_free(OCSP_REQINFO *a)

{
  ASN1_item_free((ASN1_VALUE *)a,(ASN1_ITEM *)OCSP_REQINFO_it);
  return;
}

