
char * SSL_rstate_string_long(SSL *s)

{
  uint uVar1;
  
  uVar1 = s[3].tlsext_hb_seq;
  if (uVar1 == 0xf1) {
    return "read body";
  }
  if (uVar1 != 0xf2) {
    if (uVar1 != 0xf0) {
      return "unknown";
    }
    return "read header";
  }
  return "read done";
}

