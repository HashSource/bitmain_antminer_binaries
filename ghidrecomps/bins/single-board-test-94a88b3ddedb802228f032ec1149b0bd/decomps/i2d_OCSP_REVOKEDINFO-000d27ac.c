
int i2d_OCSP_REVOKEDINFO(OCSP_REVOKEDINFO *a,uchar **out)

{
  int iVar1;
  
  iVar1 = ASN1_item_i2d((ASN1_VALUE *)a,out,DAT_000d27b4);
  return iVar1;
}

