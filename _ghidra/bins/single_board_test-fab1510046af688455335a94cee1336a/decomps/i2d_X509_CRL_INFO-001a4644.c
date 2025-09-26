
int i2d_X509_CRL_INFO(X509_CRL_INFO *a,uchar **out)

{
  int iVar1;
  
  iVar1 = ASN1_item_i2d((ASN1_VALUE *)a,out,(ASN1_ITEM *)&X509_CRL_INFO_it);
  return iVar1;
}

