
void PKCS7_SIGNER_INFO_free(PKCS7_SIGNER_INFO *a)

{
  ASN1_item_free((ASN1_VALUE *)a,(ASN1_ITEM *)PKCS7_SIGNER_INFO_it);
  return;
}

