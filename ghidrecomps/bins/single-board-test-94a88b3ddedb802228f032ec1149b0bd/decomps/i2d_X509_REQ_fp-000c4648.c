
int i2d_X509_REQ_fp(FILE *fp,X509_REQ *req)

{
  int iVar1;
  
  iVar1 = ASN1_item_i2d_fp((ASN1_ITEM *)X509_REQ_it,fp,req);
  return iVar1;
}

