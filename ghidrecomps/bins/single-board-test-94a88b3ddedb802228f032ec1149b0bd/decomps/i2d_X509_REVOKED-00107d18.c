
int i2d_X509_REVOKED(X509_REVOKED *a,uchar **out)

{
  int iVar1;
  
  iVar1 = ASN1_item_i2d((ASN1_VALUE *)a,out,DAT_00107d20);
  return iVar1;
}

