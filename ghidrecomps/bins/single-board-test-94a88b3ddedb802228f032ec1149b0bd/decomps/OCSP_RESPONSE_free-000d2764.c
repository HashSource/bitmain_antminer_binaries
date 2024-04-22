
void OCSP_RESPONSE_free(OCSP_RESPONSE *a)

{
  ASN1_item_free((ASN1_VALUE *)a,DAT_000d276c);
  return;
}

