
void PKCS7_ENCRYPT_free(PKCS7_ENCRYPT *a)

{
  ASN1_item_free((ASN1_VALUE *)a,DAT_000cf12c);
  return;
}

