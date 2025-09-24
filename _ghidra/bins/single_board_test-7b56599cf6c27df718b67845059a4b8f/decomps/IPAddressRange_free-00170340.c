
void IPAddressRange_free(IPAddressRange *a)

{
  ASN1_item_free((ASN1_VALUE *)a,(ASN1_ITEM *)IPAddressRange_it);
  return;
}

