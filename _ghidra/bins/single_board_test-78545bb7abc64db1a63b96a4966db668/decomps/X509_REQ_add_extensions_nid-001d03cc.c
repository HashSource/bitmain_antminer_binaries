
int X509_REQ_add_extensions_nid(X509_REQ *req,stack_st_X509_EXTENSION *exts,int nid)

{
  int iVar1;
  uchar *local_1c;
  
  local_1c = (uchar *)0x0;
  iVar1 = ASN1_item_i2d((ASN1_VALUE *)exts,&local_1c,(ASN1_ITEM *)&X509_EXTENSIONS_it);
  if (iVar1 < 1) {
    iVar1 = 0;
  }
  else {
    iVar1 = X509_REQ_add1_attr_by_NID(req,nid,0x10,local_1c,iVar1);
    CRYPTO_free(local_1c);
  }
  return iVar1;
}

