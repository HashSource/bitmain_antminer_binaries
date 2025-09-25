
char * OPENSSL_cipher_name(int param_1)

{
  SSL_CIPHER *c;
  char *pcVar1;
  
  if (param_1 != 0) {
    c = (SSL_CIPHER *)ssl3_get_cipher_by_std_name();
    pcVar1 = SSL_CIPHER_get_name(c);
    return pcVar1;
  }
  return "(NONE)";
}

