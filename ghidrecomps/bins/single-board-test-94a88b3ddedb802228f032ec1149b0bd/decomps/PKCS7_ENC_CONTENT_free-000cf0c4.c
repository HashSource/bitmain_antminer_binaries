
void PKCS7_ENC_CONTENT_free(PKCS7_ENC_CONTENT *a)

{
  ASN1_item_free((ASN1_VALUE *)a,DAT_000cf0cc);
  return;
}

