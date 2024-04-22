
ASN1_TYPE * d2i_ASN1_TYPE(ASN1_TYPE **a,uchar **in,long len)

{
  ASN1_TYPE *pAVar1;
  
  pAVar1 = (ASN1_TYPE *)ASN1_item_d2i((ASN1_VALUE **)a,in,len,DAT_000bbdd0);
  return pAVar1;
}

