
void OCSP_REVOKEDINFO_free(OCSP_REVOKEDINFO *a)

{
  ASN1_item_free((ASN1_VALUE *)a,DAT_000d27cc);
  return;
}

