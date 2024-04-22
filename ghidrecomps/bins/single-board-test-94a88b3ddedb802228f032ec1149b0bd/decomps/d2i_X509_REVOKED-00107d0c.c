
X509_REVOKED * d2i_X509_REVOKED(X509_REVOKED **a,uchar **in,long len)

{
  X509_REVOKED *pXVar1;
  
  pXVar1 = (X509_REVOKED *)ASN1_item_d2i((ASN1_VALUE **)a,in,len,DAT_00107d14);
  return pXVar1;
}

