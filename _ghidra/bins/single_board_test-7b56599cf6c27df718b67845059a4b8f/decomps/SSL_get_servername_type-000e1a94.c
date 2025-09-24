
int SSL_get_servername_type(SSL *s)

{
  char *pcVar1;
  
  pcVar1 = SSL_get_servername(s,0);
  return -(uint)(pcVar1 == (char *)0x0);
}

