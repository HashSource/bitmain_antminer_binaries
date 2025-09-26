
char * SSL_rstate_string(SSL *s)

{
  uint uVar1;
  
  uVar1 = s[3].tlsext_hb_seq;
  if (uVar1 == 0xf1) {
    return "RB";
  }
  if (uVar1 != 0xf2) {
    if (uVar1 != 0xf0) {
      return "unknown";
    }
    return "RH";
  }
  return "RD";
}

