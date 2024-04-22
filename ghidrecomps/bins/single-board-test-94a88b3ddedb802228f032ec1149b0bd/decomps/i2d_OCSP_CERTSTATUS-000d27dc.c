
int i2d_OCSP_CERTSTATUS(OCSP_CERTSTATUS *a,uchar **out)

{
  int iVar1;
  
  iVar1 = ASN1_item_i2d((ASN1_VALUE *)a,out,DAT_000d27e4);
  return iVar1;
}

