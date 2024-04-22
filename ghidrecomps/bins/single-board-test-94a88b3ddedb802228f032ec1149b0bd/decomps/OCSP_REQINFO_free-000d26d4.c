
void OCSP_REQINFO_free(OCSP_REQINFO *a)

{
  ASN1_item_free((ASN1_VALUE *)a,DAT_000d26dc);
  return;
}

