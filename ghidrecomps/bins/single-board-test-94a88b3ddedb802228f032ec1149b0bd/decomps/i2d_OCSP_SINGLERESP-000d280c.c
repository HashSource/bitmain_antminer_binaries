
int i2d_OCSP_SINGLERESP(OCSP_SINGLERESP *a,uchar **out)

{
  int iVar1;
  
  iVar1 = ASN1_item_i2d((ASN1_VALUE *)a,out,DAT_000d2814);
  return iVar1;
}

