
int SSL_set_tlsext_use_srtp(SSL *ctx,char *profiles)

{
  int iVar1;
  
  iVar1 = ssl_ctx_make_profiles(profiles,&ctx[3].tlsext_debug_cb);
  return iVar1;
}

