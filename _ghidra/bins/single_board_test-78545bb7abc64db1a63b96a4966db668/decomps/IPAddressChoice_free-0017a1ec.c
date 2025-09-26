
void IPAddressChoice_free(IPAddressChoice *a)

{
  ASN1_item_free((ASN1_VALUE *)a,(ASN1_ITEM *)IPAddressChoice_it);
  return;
}

