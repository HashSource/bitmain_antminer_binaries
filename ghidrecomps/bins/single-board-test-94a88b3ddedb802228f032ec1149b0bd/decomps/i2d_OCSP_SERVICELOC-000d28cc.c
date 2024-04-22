
int i2d_OCSP_SERVICELOC(OCSP_SERVICELOC *a,uchar **out)

{
  int iVar1;
  
  iVar1 = ASN1_item_i2d((ASN1_VALUE *)a,out,DAT_000d28d4);
  return iVar1;
}

