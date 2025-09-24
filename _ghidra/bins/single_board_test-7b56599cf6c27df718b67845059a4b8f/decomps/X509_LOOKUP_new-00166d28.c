
X509_LOOKUP * X509_LOOKUP_new(X509_LOOKUP_METHOD *method)

{
  X509_LOOKUP *ctx;
  int iVar1;
  _func_1976 *p_Var2;
  
  ctx = (X509_LOOKUP *)CRYPTO_zalloc(0x14,"crypto/x509/x509_lu.c");
  if (ctx == (X509_LOOKUP *)0x0) {
    ERR_put_error(0xb,0x9b,0x41,"crypto/x509/x509_lu.c",0x17);
  }
  else {
    p_Var2 = method->new_item;
    ctx->method = method;
    if ((p_Var2 != (_func_1976 *)0x0) && (iVar1 = (*p_Var2)(ctx), iVar1 == 0)) {
      CRYPTO_free(ctx);
      ctx = (X509_LOOKUP *)0x0;
    }
  }
  return ctx;
}

