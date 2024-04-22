
void Curl_ssl_kill_session(undefined4 *param_1)

{
  if ((SSL_SESSION *)param_1[1] != (SSL_SESSION *)0x0) {
    Curl_ossl_session_free((SSL_SESSION *)param_1[1]);
    param_1[1] = 0;
    param_1[3] = 0;
    Curl_free_ssl_config(param_1 + 5);
    (**DAT_0003cac0)(*param_1);
    *param_1 = 0;
  }
  return;
}

