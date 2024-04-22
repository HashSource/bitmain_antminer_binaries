
void PKCS7_SIGNED_free(PKCS7_SIGNED *a)

{
  ASN1_item_free((ASN1_VALUE *)a,DAT_000cefdc);
  return;
}

