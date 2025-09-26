
int X509_CRL_digest(X509_CRL *data,EVP_MD *type,uchar *md,uint *len)

{
  int iVar1;
  
  iVar1 = ASN1_item_digest((ASN1_ITEM *)X509_CRL_it,type,data,md,len);
  return iVar1;
}

