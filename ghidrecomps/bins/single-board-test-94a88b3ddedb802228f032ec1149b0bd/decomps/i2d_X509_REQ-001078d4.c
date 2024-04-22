
int i2d_X509_REQ(X509_REQ *a,uchar **out)

{
  int iVar1;
  
  iVar1 = ASN1_item_i2d((ASN1_VALUE *)a,out,DAT_001078dc);
  return iVar1;
}

