
void PKCS7_ENVELOPE_free(PKCS7_ENVELOPE *a)

{
  ASN1_item_free((ASN1_VALUE *)a,(ASN1_ITEM *)PKCS7_ENVELOPE_it);
  return;
}

