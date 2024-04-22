
void PKCS7_SIGNER_INFO_free(PKCS7_SIGNER_INFO *a)

{
  ASN1_item_free((ASN1_VALUE *)a,DAT_000cf00c);
  return;
}

