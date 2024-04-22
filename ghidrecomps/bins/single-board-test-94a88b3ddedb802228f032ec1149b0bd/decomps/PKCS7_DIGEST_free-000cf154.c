
void PKCS7_DIGEST_free(PKCS7_DIGEST *a)

{
  ASN1_item_free((ASN1_VALUE *)a,DAT_000cf15c);
  return;
}

