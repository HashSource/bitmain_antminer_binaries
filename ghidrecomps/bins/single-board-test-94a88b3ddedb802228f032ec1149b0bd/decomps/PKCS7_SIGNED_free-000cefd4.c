
void PKCS7_SIGNED_free(PKCS7_SIGNED *a)

{
  ASN1_item_free((ASN1_VALUE *)a,(ASN1_ITEM *)PKCS7_SIGNED_it);
  return;
}

