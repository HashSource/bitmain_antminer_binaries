
char * SSL_CIPHER_get_version(SSL_CIPHER *c)

{
  char *pcVar1;
  
  if (c == (SSL_CIPHER *)0x0) {
    return "(NONE)";
  }
  if (c->algo_strength != 0x301) {
    pcVar1 = (char *)ssl_protocol_to_string();
    return pcVar1;
  }
  return "TLSv1.0";
}

