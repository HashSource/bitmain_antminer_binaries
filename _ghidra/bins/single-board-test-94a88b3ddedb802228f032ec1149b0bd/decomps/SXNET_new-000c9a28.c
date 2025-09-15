
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

SXNET * SXNET_new(void)

{
  SXNET *pSVar1;
  
  pSVar1 = (SXNET *)ASN1_item_new((ASN1_ITEM *)SXNET_it);
  return pSVar1;
}

