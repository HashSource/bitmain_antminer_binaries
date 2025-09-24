
void IPAddressOrRange_free(IPAddressOrRange *a)

{
  ASN1_item_free((ASN1_VALUE *)a,(ASN1_ITEM *)IPAddressOrRange_it);
  return;
}

