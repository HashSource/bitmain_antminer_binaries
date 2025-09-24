
int SSL_CTX_add_client_CA(SSL_CTX *ctx,X509 *x)

{
  X509_NAME *pXVar1;
  int iVar2;
  ulong uVar3;
  
  if (x != (X509 *)0x0) {
    if (ctx->mode == 0) {
      uVar3 = OPENSSL_sk_new_null();
      ctx->mode = uVar3;
      if (uVar3 == 0) {
        return 0;
      }
    }
    pXVar1 = X509_get_subject_name(x);
    pXVar1 = X509_NAME_dup(pXVar1);
    if (pXVar1 != (X509_NAME *)0x0) {
      iVar2 = OPENSSL_sk_push(ctx->mode,pXVar1);
      if (iVar2 == 0) {
        X509_NAME_free(pXVar1);
        return 0;
      }
      return 1;
    }
  }
  return 0;
}

