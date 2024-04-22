
DSA * d2i_DSAPublicKey(DSA **a,uchar **pp,long length)

{
  DSA *pDVar1;
  
  pDVar1 = (DSA *)ASN1_item_d2i((ASN1_VALUE **)a,pp,length,DAT_000a4828);
  return pDVar1;
}

