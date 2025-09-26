
char * SSL_get_version(SSL *s)

{
  char *pcVar1;
  int iVar2;
  
  iVar2 = s->version;
  if (iVar2 == 0x303) {
    return "TLSv1.2";
  }
  if (iVar2 == 0x302) {
    return "TLSv1.1";
  }
  if (iVar2 == 0x301) {
    return "TLSv1";
  }
  if (iVar2 == 0x300) {
    return "SSLv3";
  }
  if (iVar2 == 2) {
    return "SSLv2";
  }
  if (iVar2 == 0x100) {
    return "DTLSv0.9";
  }
  if (iVar2 == 0xfeff) {
    return "DTLSv1";
  }
  if (iVar2 == 0xfefd) {
    pcVar1 = "DTLSv1.2";
  }
  else {
    pcVar1 = "unknown";
  }
  return pcVar1;
}

