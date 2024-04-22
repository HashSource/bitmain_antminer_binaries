
char * SSL_CIPHER_get_version(SSL_CIPHER *c)

{
  char cVar1;
  char *pcVar2;
  
  if (c == (SSL_CIPHER *)0x0) {
    return DAT_000810dc;
  }
  cVar1 = *(char *)((int)&c->id + 3);
  if (cVar1 != '\x03') {
    pcVar2 = DAT_000810d4;
    if (cVar1 == '\x02') {
      pcVar2 = DAT_000810d0;
    }
    return pcVar2;
  }
  return DAT_000810d8;
}

