
RSA * d2i_RSAPublicKey(RSA **a,uchar **in,long len)

{
  RSA *pRVar1;
  
  pRVar1 = (RSA *)ASN1_item_d2i((ASN1_VALUE **)a,in,len,DAT_000a44c0);
  return pRVar1;
}

