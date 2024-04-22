
int X509_digest(X509 *data,EVP_MD *type,uchar *md,uint *len)

{
  int iVar1;
  
  iVar1 = ASN1_item_digest((ASN1_ITEM *)X509_it,type,data,md,len);
  return iVar1;
}

