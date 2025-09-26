
void OCSP_CERTID_free(OCSP_CERTID *a)

{
  ASN1_item_free((ASN1_VALUE *)a,(ASN1_ITEM *)OCSP_CERTID_it);
  return;
}

