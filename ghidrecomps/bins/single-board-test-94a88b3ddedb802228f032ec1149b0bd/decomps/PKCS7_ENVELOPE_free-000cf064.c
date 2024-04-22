
void PKCS7_ENVELOPE_free(PKCS7_ENVELOPE *a)

{
  ASN1_item_free((ASN1_VALUE *)a,DAT_000cf06c);
  return;
}

