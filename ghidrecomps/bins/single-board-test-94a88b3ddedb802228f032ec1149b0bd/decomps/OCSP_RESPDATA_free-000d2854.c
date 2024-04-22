
void OCSP_RESPDATA_free(OCSP_RESPDATA *a)

{
  ASN1_item_free((ASN1_VALUE *)a,DAT_000d285c);
  return;
}

