
int CMS_ContentInfo_print_ctx(BIO *out,CMS_ContentInfo *x,int indent,ASN1_PCTX *pctx)

{
  int iVar1;
  
  iVar1 = ASN1_item_print(out,(ASN1_VALUE *)x,indent,(ASN1_ITEM *)CMS_ContentInfo_it,pctx);
  return iVar1;
}

