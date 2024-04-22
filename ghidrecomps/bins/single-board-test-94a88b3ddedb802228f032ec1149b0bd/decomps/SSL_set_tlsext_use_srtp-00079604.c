
int SSL_set_tlsext_use_srtp(SSL *ctx,char *profiles)

{
  int iVar1;
  
  iVar1 = ssl_ctx_make_profiles(profiles,&ctx->next_proto_negotiated_len);
  return iVar1;
}

