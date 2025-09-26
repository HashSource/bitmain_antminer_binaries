
int i2d_X509_EXTENSION(X509_EXTENSION *a,uchar **out)

{
  int iVar1;
  
  iVar1 = ASN1_item_i2d((ASN1_VALUE *)a,out,(ASN1_ITEM *)&X509_EXTENSION_it);
  return iVar1;
}

