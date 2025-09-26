
char * ssl_protocol_to_string(int param_1)

{
  if (param_1 == 0x302) {
    return "TLSv1.1";
  }
  if (param_1 < 0x303) {
    if (param_1 == 0x300) {
      return "SSLv3";
    }
    if (0x300 < param_1) {
      return "TLSv1";
    }
    if (param_1 == 0x100) {
      return "DTLSv0.9";
    }
  }
  else {
    if (param_1 == 0x304) {
      return "TLSv1.3";
    }
    if (param_1 < 0x304) {
      return "TLSv1.2";
    }
    if (param_1 == 0xfefd) {
      return "DTLSv1.2";
    }
    if (param_1 == 0xfeff) {
      return "DTLSv1";
    }
  }
  return "unknown";
}

