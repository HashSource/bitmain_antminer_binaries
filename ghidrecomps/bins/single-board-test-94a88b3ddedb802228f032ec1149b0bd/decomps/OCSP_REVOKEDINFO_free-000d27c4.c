
void OCSP_REVOKEDINFO_free(OCSP_REVOKEDINFO *a)

{
  ASN1_item_free((ASN1_VALUE *)a,(ASN1_ITEM *)OCSP_REVOKEDINFO_it);
  return;
}

