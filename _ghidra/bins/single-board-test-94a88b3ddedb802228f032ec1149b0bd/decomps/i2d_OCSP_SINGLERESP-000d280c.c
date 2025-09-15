
int i2d_OCSP_SINGLERESP(OCSP_SINGLERESP *a,uchar **out)

{
  int iVar1;
  
  iVar1 = ASN1_item_i2d((ASN1_VALUE *)a,out,(ASN1_ITEM *)OCSP_SINGLERESP_it);
  return iVar1;
}

