
void Curl_ssl_close(int param_1,int param_2)

{
  param_1 = param_1 + param_2 * 0x18;
  if (*(SSL **)(param_1 + 0x188) != (SSL *)0x0) {
    SSL_shutdown(*(SSL **)(param_1 + 0x188));
    SSL_set_connect_state(*(SSL **)(param_1 + 0x188));
    SSL_free(*(SSL **)(param_1 + 0x188));
    *(undefined4 *)(param_1 + 0x188) = 0;
  }
  if (*(SSL_CTX **)(param_1 + 0x184) != (SSL_CTX *)0x0) {
    SSL_CTX_free(*(SSL_CTX **)(param_1 + 0x184));
    *(undefined4 *)(param_1 + 0x184) = 0;
  }
  return;
}

