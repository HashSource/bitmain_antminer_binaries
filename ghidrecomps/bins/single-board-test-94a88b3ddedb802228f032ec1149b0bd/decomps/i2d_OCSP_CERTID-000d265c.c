
int i2d_OCSP_CERTID(OCSP_CERTID *a,uchar **out)

{
  int iVar1;
  
  iVar1 = ASN1_item_i2d((ASN1_VALUE *)a,out,DAT_000d2664);
  return iVar1;
}

