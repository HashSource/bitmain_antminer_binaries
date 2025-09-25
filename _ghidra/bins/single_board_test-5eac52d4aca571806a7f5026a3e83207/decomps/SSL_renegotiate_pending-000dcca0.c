
int SSL_renegotiate_pending(SSL *s)

{
  char *pcVar1;
  
  pcVar1 = s[3].tlsext_hostname;
  if (pcVar1 != (char *)0x0) {
    pcVar1 = (char *)0x1;
  }
  return (int)pcVar1;
}

