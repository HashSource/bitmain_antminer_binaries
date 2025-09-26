
int ENGINE_set_load_ssl_client_cert_function(ENGINE *e,ENGINE_SSL_CLIENT_CERT_PTR loadssl_f)

{
  *(ENGINE_SSL_CLIENT_CERT_PTR *)(e + 0x4c) = loadssl_f;
  return 1;
}

