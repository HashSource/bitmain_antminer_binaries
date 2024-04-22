
void OCSP_BASICRESP_free(OCSP_BASICRESP *a)

{
  ASN1_item_free((ASN1_VALUE *)a,DAT_000d288c);
  return;
}

