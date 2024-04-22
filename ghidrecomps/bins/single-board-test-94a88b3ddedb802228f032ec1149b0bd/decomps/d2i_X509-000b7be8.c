
X509 * d2i_X509(X509 **a,uchar **in,long len)

{
  X509 *pXVar1;
  
  pXVar1 = (X509 *)ASN1_item_d2i((ASN1_VALUE **)a,in,len,DAT_000b7bf0);
  return pXVar1;
}

