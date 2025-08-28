
int i2d_PKCS12_SAFEBAG(PKCS12_SAFEBAG *a,uchar **out)

{
  int iVar1;
  
  iVar1 = ASN1_item_i2d((ASN1_VALUE *)a,out,(ASN1_ITEM *)PKCS12_SAFEBAG_it);
  return iVar1;
}

