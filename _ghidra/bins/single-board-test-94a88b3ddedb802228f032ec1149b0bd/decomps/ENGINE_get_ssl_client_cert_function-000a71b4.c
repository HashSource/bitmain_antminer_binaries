
ENGINE_SSL_CLIENT_CERT_PTR ENGINE_get_ssl_client_cert_function(ENGINE *e)

{
  return *(ENGINE_SSL_CLIENT_CERT_PTR *)(e + 0x4c);
}

