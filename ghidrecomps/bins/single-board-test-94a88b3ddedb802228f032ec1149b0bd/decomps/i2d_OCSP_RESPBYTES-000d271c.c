
int i2d_OCSP_RESPBYTES(OCSP_RESPBYTES *a,uchar **out)

{
  int iVar1;
  
  iVar1 = ASN1_item_i2d((ASN1_VALUE *)a,out,DAT_000d2724);
  return iVar1;
}

