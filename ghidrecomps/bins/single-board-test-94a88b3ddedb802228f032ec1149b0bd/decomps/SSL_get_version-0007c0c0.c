
char * SSL_get_version(SSL *s)

{
  char *pcVar1;
  int iVar2;
  
  iVar2 = s->version;
  if (iVar2 == 0x303) {
    return DAT_0007c128;
  }
  if (iVar2 == 0x302) {
    return DAT_0007c12c;
  }
  if (iVar2 == 0x301) {
    return DAT_0007c130;
  }
  if (iVar2 != 0x300) {
    if (iVar2 == 2) {
      return DAT_0007c134;
    }
    if (iVar2 != 0x100) {
      if (iVar2 != 0xfeff) {
        pcVar1 = DAT_0007c11c;
        if (iVar2 == 0xfefd) {
          pcVar1 = DAT_0007c120;
        }
        return pcVar1;
      }
      return DAT_0007c13c;
    }
    return DAT_0007c138;
  }
  return DAT_0007c124;
}

