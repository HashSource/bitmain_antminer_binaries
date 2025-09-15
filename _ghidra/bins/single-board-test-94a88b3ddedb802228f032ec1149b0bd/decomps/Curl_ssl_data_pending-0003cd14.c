
SSL * Curl_ssl_data_pending(int param_1,int param_2)

{
  SSL *s;
  
  s = *(SSL **)(param_1 + param_2 * 0x18 + 0x188);
  if ((s != (SSL *)0x0) && (s = (SSL *)SSL_pending(s), s != (SSL *)0x0)) {
    s = (SSL *)0x1;
  }
  return s;
}

