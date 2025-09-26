
void PKCS7_free(PKCS7 *a)

{
  ASN1_item_free((ASN1_VALUE *)a,(ASN1_ITEM *)&PKCS7_it);
  return;
}

