
X509_REQ * d2i_X509_REQ(X509_REQ **a,uchar **in,long len)

{
  X509_REQ *pXVar1;
  
  pXVar1 = (X509_REQ *)ASN1_item_d2i((ASN1_VALUE **)a,in,len,DAT_001078d0);
  return pXVar1;
}

