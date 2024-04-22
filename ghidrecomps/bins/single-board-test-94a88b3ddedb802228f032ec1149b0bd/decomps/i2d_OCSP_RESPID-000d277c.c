
int i2d_OCSP_RESPID(OCSP_RESPID *a,uchar **out)

{
  int iVar1;
  
  iVar1 = ASN1_item_i2d((ASN1_VALUE *)a,out,DAT_000d2784);
  return iVar1;
}

