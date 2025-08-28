
void OCSP_SINGLERESP_free(OCSP_SINGLERESP *a)

{
  ASN1_item_free((ASN1_VALUE *)a,(ASN1_ITEM *)OCSP_SINGLERESP_it);
  return;
}

