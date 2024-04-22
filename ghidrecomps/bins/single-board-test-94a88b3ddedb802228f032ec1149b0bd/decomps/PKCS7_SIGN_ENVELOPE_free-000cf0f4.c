
void PKCS7_SIGN_ENVELOPE_free(PKCS7_SIGN_ENVELOPE *a)

{
  ASN1_item_free((ASN1_VALUE *)a,DAT_000cf0fc);
  return;
}

