
int i2d_X509_CERT_PAIR(X509_CERT_PAIR *a,uchar **out)

{
  int iVar1;
  
  iVar1 = ASN1_item_i2d((ASN1_VALUE *)a,out,(ASN1_ITEM *)X509_CERT_PAIR_it);
  return iVar1;
}

