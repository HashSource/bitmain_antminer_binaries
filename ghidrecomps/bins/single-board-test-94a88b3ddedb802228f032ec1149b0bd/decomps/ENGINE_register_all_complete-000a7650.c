
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int ENGINE_register_all_complete(void)

{
  ENGINE *e;
  
  e = ENGINE_get_first();
  do {
    if (e == (ENGINE *)0x0) {
      return 1;
    }
    while (*(int *)(e + 0x54) << 0x1c < 0) {
      e = ENGINE_get_next(e);
      if (e == (ENGINE *)0x0) {
        return 1;
      }
    }
    ENGINE_register_ciphers(e);
    ENGINE_register_digests(e);
    ENGINE_register_RSA(e);
    ENGINE_register_DSA(e);
    ENGINE_register_DH(e);
    ENGINE_register_ECDH(e);
    ENGINE_register_ECDSA(e);
    ENGINE_register_RAND(e);
    ENGINE_register_pkey_meths(e);
    e = ENGINE_get_next(e);
  } while( true );
}

