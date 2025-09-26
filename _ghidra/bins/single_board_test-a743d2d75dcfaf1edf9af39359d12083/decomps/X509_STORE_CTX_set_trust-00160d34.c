
int X509_STORE_CTX_set_trust(X509_STORE_CTX *ctx,int trust)

{
  int iVar1;
  
  iVar1 = X509_STORE_CTX_purpose_inherit(ctx,0,0,trust);
  return iVar1;
}

