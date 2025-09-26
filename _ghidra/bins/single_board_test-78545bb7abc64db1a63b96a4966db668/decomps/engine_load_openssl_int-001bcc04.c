
void engine_load_openssl_int(void)

{
  ENGINE *e;
  int iVar1;
  RSA_METHOD *rsa_meth;
  DSA_METHOD *dsa_meth;
  undefined4 uVar2;
  DH_METHOD *dh_meth;
  RAND_METHOD *rand_meth;
  
  e = ENGINE_new();
  if (e == (ENGINE *)0x0) {
    return;
  }
  iVar1 = ENGINE_set_id(e,"openssl");
  if (((iVar1 != 0) && (iVar1 = ENGINE_set_name(e,"Software engine support"), iVar1 != 0)) &&
     (iVar1 = ENGINE_set_destroy_function(e,(ENGINE_GEN_INT_FUNC_PTR)0x1bc9a1), iVar1 != 0)) {
    rsa_meth = RSA_get_default_method();
    iVar1 = ENGINE_set_RSA(e,rsa_meth);
    if (iVar1 != 0) {
      dsa_meth = DSA_get_default_method();
      iVar1 = ENGINE_set_DSA(e,dsa_meth);
      if (iVar1 != 0) {
        uVar2 = EC_KEY_OpenSSL();
        iVar1 = ENGINE_set_EC(e,uVar2);
        if (iVar1 != 0) {
          dh_meth = DH_get_default_method();
          iVar1 = ENGINE_set_DH(e,dh_meth);
          if (iVar1 != 0) {
            rand_meth = (RAND_METHOD *)RAND_OpenSSL();
            iVar1 = ENGINE_set_RAND(e,rand_meth);
            if (((iVar1 != 0) &&
                (iVar1 = ENGINE_set_ciphers(e,(ENGINE_CIPHERS_PTR)0x1bc8f5), iVar1 != 0)) &&
               ((iVar1 = ENGINE_set_digests(e,(ENGINE_DIGESTS_PTR)0x1bca4d), iVar1 != 0 &&
                (iVar1 = ENGINE_set_load_privkey_function(e,(ENGINE_LOAD_KEY_PTR)0x1bc769),
                iVar1 != 0)))) {
              ENGINE_add(e);
              ENGINE_free(e);
              ERR_clear_error();
              return;
            }
          }
        }
      }
    }
  }
  ENGINE_free(e);
  return;
}

