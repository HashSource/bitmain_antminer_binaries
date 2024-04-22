
void OCSP_CRLID_free(OCSP_CRLID *a)

{
  ASN1_item_free((ASN1_VALUE *)a,DAT_000d28bc);
  return;
}

