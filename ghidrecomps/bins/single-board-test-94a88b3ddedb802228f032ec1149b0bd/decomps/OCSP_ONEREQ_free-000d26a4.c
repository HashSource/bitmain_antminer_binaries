
void OCSP_ONEREQ_free(OCSP_ONEREQ *a)

{
  ASN1_item_free((ASN1_VALUE *)a,DAT_000d26ac);
  return;
}

