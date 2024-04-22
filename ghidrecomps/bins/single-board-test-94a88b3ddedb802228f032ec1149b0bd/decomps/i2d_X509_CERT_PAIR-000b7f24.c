
int i2d_X509_CERT_PAIR(X509_CERT_PAIR *a,uchar **out)

{
  int iVar1;
  
  iVar1 = ASN1_item_i2d((ASN1_VALUE *)a,out,DAT_000b7f2c);
  return iVar1;
}

