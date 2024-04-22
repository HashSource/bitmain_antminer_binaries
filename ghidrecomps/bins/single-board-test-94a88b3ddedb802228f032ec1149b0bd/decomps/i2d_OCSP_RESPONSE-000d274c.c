
int i2d_OCSP_RESPONSE(OCSP_RESPONSE *a,uchar **out)

{
  int iVar1;
  
  iVar1 = ASN1_item_i2d((ASN1_VALUE *)a,out,DAT_000d2754);
  return iVar1;
}

