
void PKCS7_ISSUER_AND_SERIAL_free(PKCS7_ISSUER_AND_SERIAL *a)

{
  ASN1_item_free((ASN1_VALUE *)a,DAT_000cf03c);
  return;
}

