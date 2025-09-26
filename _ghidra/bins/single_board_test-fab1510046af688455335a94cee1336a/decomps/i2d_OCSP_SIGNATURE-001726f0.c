
int i2d_OCSP_SIGNATURE(OCSP_SIGNATURE *a,uchar **out)

{
  int iVar1;
  
  iVar1 = ASN1_item_i2d((ASN1_VALUE *)a,out,(ASN1_ITEM *)&OCSP_SIGNATURE_it);
  return iVar1;
}

