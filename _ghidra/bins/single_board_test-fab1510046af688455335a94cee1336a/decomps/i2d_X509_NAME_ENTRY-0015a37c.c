
int i2d_X509_NAME_ENTRY(X509_NAME_ENTRY *a,uchar **out)

{
  int iVar1;
  
  iVar1 = ASN1_item_i2d((ASN1_VALUE *)a,out,(ASN1_ITEM *)&X509_NAME_ENTRY_it);
  return iVar1;
}

