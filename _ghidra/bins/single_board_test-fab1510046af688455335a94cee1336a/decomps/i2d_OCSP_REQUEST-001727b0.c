
int i2d_OCSP_REQUEST(OCSP_REQUEST *a,uchar **out)

{
  int iVar1;
  
  iVar1 = ASN1_item_i2d((ASN1_VALUE *)a,out,(ASN1_ITEM *)OCSP_REQUEST_it);
  return iVar1;
}

