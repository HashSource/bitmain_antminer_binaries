
void OCSP_RESPBYTES_free(OCSP_RESPBYTES *a)

{
  ASN1_item_free((ASN1_VALUE *)a,DAT_000d273c);
  return;
}

