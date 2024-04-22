
SXNET * d2i_SXNET(SXNET **a,uchar **in,long len)

{
  SXNET *pSVar1;
  
  pSVar1 = (SXNET *)ASN1_item_d2i((ASN1_VALUE **)a,in,len,DAT_000c9a18);
  return pSVar1;
}

