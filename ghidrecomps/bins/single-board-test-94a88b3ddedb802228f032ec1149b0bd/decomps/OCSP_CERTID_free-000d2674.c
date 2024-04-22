
void OCSP_CERTID_free(OCSP_CERTID *a)

{
  ASN1_item_free((ASN1_VALUE *)a,DAT_000d267c);
  return;
}

