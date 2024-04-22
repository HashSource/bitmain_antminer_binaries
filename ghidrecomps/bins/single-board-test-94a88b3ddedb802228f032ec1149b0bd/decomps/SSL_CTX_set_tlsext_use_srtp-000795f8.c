
int SSL_CTX_set_tlsext_use_srtp(SSL_CTX *ctx,char *profiles)

{
  int iVar1;
  
  iVar1 = ssl_ctx_make_profiles(profiles,&ctx[1].stats.sess_connect_good);
  return iVar1;
}

