
int ENGINE_register_complete(ENGINE *e)

{
  ENGINE_register_ciphers(e);
  ENGINE_register_digests(e);
  ENGINE_register_RSA(e);
  ENGINE_register_DSA(e);
  ENGINE_register_DH(e);
  ENGINE_register_ECDH(e);
  ENGINE_register_ECDSA(e);
  ENGINE_register_RAND(e);
  ENGINE_register_pkey_meths(e);
  return 1;
}

