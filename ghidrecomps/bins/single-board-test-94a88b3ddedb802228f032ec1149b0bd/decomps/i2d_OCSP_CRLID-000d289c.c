
int i2d_OCSP_CRLID(OCSP_CRLID *a,uchar **out)

{
  int iVar1;
  
  iVar1 = ASN1_item_i2d((ASN1_VALUE *)a,out,DAT_000d28a4);
  return iVar1;
}

