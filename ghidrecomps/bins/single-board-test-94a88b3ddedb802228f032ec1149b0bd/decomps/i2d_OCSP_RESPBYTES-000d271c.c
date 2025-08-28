
int i2d_OCSP_RESPBYTES(OCSP_RESPBYTES *a,uchar **out)

{
  int iVar1;
  
  iVar1 = ASN1_item_i2d((ASN1_VALUE *)a,out,(ASN1_ITEM *)OCSP_RESPBYTES_it);
  return iVar1;
}

