
int SSL_CTX_add_client_CA(SSL_CTX *ctx,X509 *x)

{
  X509_NAME *pXVar1;
  int iVar2;
  _STACK *p_Var3;
  
  if (x != (X509 *)0x0) {
    if (ctx->client_CA == (stack_st_X509_NAME *)0x0) {
      p_Var3 = sk_new_null();
      ctx->client_CA = (stack_st_X509_NAME *)p_Var3;
      if (p_Var3 == (_STACK *)0x0) {
        return 0;
      }
    }
    pXVar1 = X509_get_subject_name(x);
    pXVar1 = X509_NAME_dup(pXVar1);
    if (pXVar1 != (X509_NAME *)0x0) {
      iVar2 = sk_push(&ctx->client_CA->stack,pXVar1);
      if (iVar2 == 0) {
        X509_NAME_free(pXVar1);
        return 0;
      }
      return 1;
    }
  }
  return 0;
}

