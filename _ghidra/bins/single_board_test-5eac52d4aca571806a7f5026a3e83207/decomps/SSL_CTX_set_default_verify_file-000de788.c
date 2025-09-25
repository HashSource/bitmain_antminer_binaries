
undefined4 SSL_CTX_set_default_verify_file(int param_1)

{
  X509_LOOKUP_METHOD *m;
  X509_LOOKUP *ctx;
  X509_STORE *v;
  
  v = *(X509_STORE **)(param_1 + 0x10);
  m = X509_LOOKUP_file();
  ctx = X509_STORE_add_lookup(v,m);
  if (ctx != (X509_LOOKUP *)0x0) {
    X509_LOOKUP_ctrl(ctx,1,(char *)0x0,3,(char **)0x0);
    ERR_clear_error();
    return 1;
  }
  return 0;
}

