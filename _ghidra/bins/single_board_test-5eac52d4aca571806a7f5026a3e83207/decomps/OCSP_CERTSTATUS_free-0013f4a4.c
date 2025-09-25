
void OCSP_CERTSTATUS_free(OCSP_CERTSTATUS *a)

{
  ASN1_item_free((ASN1_VALUE *)a,(ASN1_ITEM *)OCSP_CERTSTATUS_it);
  return;
}

