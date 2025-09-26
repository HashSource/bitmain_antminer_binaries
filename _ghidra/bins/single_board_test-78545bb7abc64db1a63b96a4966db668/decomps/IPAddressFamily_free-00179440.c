
void IPAddressFamily_free(IPAddressFamily *a)

{
  ASN1_item_free((ASN1_VALUE *)a,(ASN1_ITEM *)IPAddressFamily_it);
  return;
}

