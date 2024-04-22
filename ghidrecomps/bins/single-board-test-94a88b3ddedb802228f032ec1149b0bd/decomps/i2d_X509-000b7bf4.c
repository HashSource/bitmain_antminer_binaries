
int i2d_X509(X509 *a,uchar **out)

{
  int iVar1;
  
  iVar1 = ASN1_item_i2d((ASN1_VALUE *)a,out,DAT_000b7bfc);
  return iVar1;
}

