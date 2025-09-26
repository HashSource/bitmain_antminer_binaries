
int SSL_CTX_set_generate_session_id(SSL_CTX *param_1,GEN_SESSION_CB param_2)

{
  CRYPTO_THREAD_write_lock(param_1[1].client_CA);
  param_1->client_cert_engine = (ENGINE *)param_2;
  CRYPTO_THREAD_unlock(param_1[1].client_CA);
  return 1;
}

