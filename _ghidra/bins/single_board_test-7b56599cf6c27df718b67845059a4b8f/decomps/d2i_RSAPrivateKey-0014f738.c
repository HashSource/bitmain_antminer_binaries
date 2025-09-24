
RSA * d2i_RSAPrivateKey(RSA **a,uchar **in,long len)

{
  RSA *pRVar1;
  
  pRVar1 = (RSA *)ASN1_item_d2i((ASN1_VALUE **)a,in,len,(ASN1_ITEM *)RSAPrivateKey_it);
  return pRVar1;
}

