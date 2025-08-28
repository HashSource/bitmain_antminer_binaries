
void SXNET_free(SXNET *a)

{
  ASN1_item_free((ASN1_VALUE *)a,(ASN1_ITEM *)SXNET_it);
  return;
}

