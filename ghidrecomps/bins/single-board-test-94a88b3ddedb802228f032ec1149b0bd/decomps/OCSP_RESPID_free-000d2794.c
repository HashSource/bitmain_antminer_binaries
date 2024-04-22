
void OCSP_RESPID_free(OCSP_RESPID *a)

{
  ASN1_item_free((ASN1_VALUE *)a,DAT_000d279c);
  return;
}

