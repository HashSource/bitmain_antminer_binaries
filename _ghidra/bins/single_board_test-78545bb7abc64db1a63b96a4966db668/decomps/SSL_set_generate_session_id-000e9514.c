
int SSL_set_generate_session_id(SSL *param_1,GEN_SESSION_CB param_2)

{
  CRYPTO_THREAD_write_lock(param_1[9].first_packet);
  param_1[2].tlsext_ellipticcurvelist = (uchar *)param_2;
  CRYPTO_THREAD_unlock(param_1[9].first_packet);
  return 1;
}

