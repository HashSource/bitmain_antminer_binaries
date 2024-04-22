
int X509_REQ_sign_ctx(X509_REQ *x,EVP_MD_CTX *ctx)

{
  int iVar1;
  
  iVar1 = ASN1_item_sign_ctx((ASN1_ITEM *)&X509_REQ_INFO_it,x->sig_alg,(X509_ALGOR *)0x0,
                             x->signature,x->req_info,ctx);
  return iVar1;
}

