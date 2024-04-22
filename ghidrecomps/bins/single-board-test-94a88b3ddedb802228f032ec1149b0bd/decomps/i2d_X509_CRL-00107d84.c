
int i2d_X509_CRL(X509_CRL *a,uchar **out)

{
  int iVar1;
  
  iVar1 = ASN1_item_i2d((ASN1_VALUE *)a,out,DAT_00107d8c);
  return iVar1;
}

