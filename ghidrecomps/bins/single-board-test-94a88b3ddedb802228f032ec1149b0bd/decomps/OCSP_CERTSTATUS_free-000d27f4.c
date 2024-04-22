
void OCSP_CERTSTATUS_free(OCSP_CERTSTATUS *a)

{
  ASN1_item_free((ASN1_VALUE *)a,DAT_000d27fc);
  return;
}

