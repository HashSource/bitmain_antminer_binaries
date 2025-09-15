
void Curl_ssl_cleanup(void)

{
  if (init_ssl != '\0') {
    Curl_ossl_cleanup();
    init_ssl = '\0';
  }
  return;
}

