
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

char * DES_options(void)

{
  if (init_8007 != 0) {
    OPENSSL_strlcpy(&buf_8008,"des(long)",0xc);
    init_8007 = 0;
  }
  return &buf_8008;
}

