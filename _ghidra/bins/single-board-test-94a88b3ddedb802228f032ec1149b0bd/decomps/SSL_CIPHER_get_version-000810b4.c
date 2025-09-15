
char * SSL_CIPHER_get_version(SSL_CIPHER *c)

{
  char cVar1;
  char *pcVar2;
  
  if (c == (SSL_CIPHER *)0x0) {
    return "(NONE)";
  }
  cVar1 = *(char *)((int)&c->id + 3);
  if (cVar1 != '\x03') {
    pcVar2 = "unknown";
    if (cVar1 == '\x02') {
      pcVar2 = "SSLv2";
    }
    return pcVar2;
  }
  return "TLSv1/SSLv3";
}

