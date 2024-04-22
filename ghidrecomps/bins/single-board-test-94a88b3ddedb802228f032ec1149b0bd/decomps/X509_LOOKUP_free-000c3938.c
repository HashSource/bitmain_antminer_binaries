
void X509_LOOKUP_free(X509_LOOKUP *ctx)

{
  _func_1977 *p_Var1;
  
  if (ctx != (X509_LOOKUP *)0x0) {
    if ((ctx->method != (X509_LOOKUP_METHOD *)0x0) &&
       (p_Var1 = ctx->method->free, p_Var1 != (_func_1977 *)0x0)) {
      (*p_Var1)(ctx);
    }
    CRYPTO_free(ctx);
    return;
  }
  return;
}

