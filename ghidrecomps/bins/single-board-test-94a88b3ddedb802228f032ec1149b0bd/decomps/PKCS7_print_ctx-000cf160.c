
int PKCS7_print_ctx(BIO *out,PKCS7 *x,int indent,ASN1_PCTX *pctx)

{
  int iVar1;
  
  iVar1 = ASN1_item_print(out,(ASN1_VALUE *)x,indent,(ASN1_ITEM *)&PKCS7_it,pctx);
  return iVar1;
}

