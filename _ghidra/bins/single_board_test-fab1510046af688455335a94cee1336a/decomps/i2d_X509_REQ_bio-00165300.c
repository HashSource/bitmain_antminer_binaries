
int i2d_X509_REQ_bio(BIO *bp,X509_REQ *req)

{
  int iVar1;
  
  iVar1 = ASN1_item_i2d_bio((ASN1_ITEM *)X509_REQ_it,bp,req);
  return iVar1;
}

