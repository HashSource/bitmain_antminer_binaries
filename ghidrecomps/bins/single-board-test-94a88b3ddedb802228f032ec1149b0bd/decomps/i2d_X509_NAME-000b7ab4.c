
int i2d_X509_NAME(X509_NAME *a,uchar **out)

{
  int iVar1;
  
  iVar1 = ASN1_item_i2d((ASN1_VALUE *)a,out,DAT_000b7abc);
  return iVar1;
}

