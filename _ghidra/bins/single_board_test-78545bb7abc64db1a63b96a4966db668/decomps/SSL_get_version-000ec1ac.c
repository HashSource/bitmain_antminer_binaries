
char * SSL_get_version(SSL *s)

{
  char *pcVar1;
  
  pcVar1 = (char *)ssl_protocol_to_string(s->version);
  return pcVar1;
}

