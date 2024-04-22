
X509_PUBKEY * d2i_X509_PUBKEY(X509_PUBKEY **a,uchar **in,long len)

{
  X509_PUBKEY *pXVar1;
  
  pXVar1 = (X509_PUBKEY *)ASN1_item_d2i((ASN1_VALUE **)a,in,len,(ASN1_ITEM *)&X509_PUBKEY_it);
  return pXVar1;
}

