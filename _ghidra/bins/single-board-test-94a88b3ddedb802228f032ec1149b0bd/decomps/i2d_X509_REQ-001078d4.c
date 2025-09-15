
int i2d_X509_REQ(X509_REQ *a,uchar **out)

{
  int iVar1;
  
  iVar1 = ASN1_item_i2d((ASN1_VALUE *)a,out,(ASN1_ITEM *)X509_REQ_it);
  return iVar1;
}

