
void PKCS12_SAFEBAG_free(PKCS12_SAFEBAG *a)

{
  ASN1_item_free((ASN1_VALUE *)a,(ASN1_ITEM *)PKCS12_SAFEBAG_it);
  return;
}

