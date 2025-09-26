
int i2d_X509_REQ_INFO(X509_REQ_INFO *a,uchar **out)

{
  int iVar1;
  
  iVar1 = ASN1_item_i2d((ASN1_VALUE *)a,out,(ASN1_ITEM *)&X509_REQ_INFO_it);
  return iVar1;
}

