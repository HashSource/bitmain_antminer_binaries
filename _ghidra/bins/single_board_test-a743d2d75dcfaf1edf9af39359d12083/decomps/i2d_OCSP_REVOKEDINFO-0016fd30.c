
int i2d_OCSP_REVOKEDINFO(OCSP_REVOKEDINFO *a,uchar **out)

{
  int iVar1;
  
  iVar1 = ASN1_item_i2d((ASN1_VALUE *)a,out,(ASN1_ITEM *)OCSP_REVOKEDINFO_it);
  return iVar1;
}

