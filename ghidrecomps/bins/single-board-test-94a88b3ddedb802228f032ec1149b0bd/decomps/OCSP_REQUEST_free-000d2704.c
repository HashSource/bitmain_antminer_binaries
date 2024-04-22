
void OCSP_REQUEST_free(OCSP_REQUEST *a)

{
  ASN1_item_free((ASN1_VALUE *)a,DAT_000d270c);
  return;
}

