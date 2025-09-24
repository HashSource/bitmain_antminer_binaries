
DSA * d2i_DSAPublicKey(DSA **a,uchar **pp,long length)

{
  DSA *pDVar1;
  
  pDVar1 = (DSA *)ASN1_item_d2i((ASN1_VALUE **)a,pp,length,(ASN1_ITEM *)DSAPublicKey_it);
  return pDVar1;
}

