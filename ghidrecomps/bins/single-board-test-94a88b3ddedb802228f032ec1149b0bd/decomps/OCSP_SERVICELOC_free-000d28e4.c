
void OCSP_SERVICELOC_free(OCSP_SERVICELOC *a)

{
  ASN1_item_free((ASN1_VALUE *)a,DAT_000d28ec);
  return;
}

