
void OCSP_SINGLERESP_free(OCSP_SINGLERESP *a)

{
  ASN1_item_free((ASN1_VALUE *)a,DAT_000d282c);
  return;
}

