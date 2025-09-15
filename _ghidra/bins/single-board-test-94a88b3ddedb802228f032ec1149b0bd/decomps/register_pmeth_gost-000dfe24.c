
undefined4 register_pmeth_gost(int param_1,undefined4 *param_2,int param_3)

{
  EVP_PKEY_METHOD *pmeth;
  
  pmeth = EVP_PKEY_meth_new(param_1,param_3);
  *param_2 = pmeth;
  if (pmeth == (EVP_PKEY_METHOD *)0x0) {
    return 0;
  }
  if (param_1 == 0x32c) {
    EVP_PKEY_meth_set_ctrl(pmeth,(ctrl *)0xdf749,(ctrl_str *)0xdfa39);
    EVP_PKEY_meth_set_keygen((EVP_PKEY_METHOD *)*param_2,(keygen_init *)0x0,(keygen *)0xdfd75);
    EVP_PKEY_meth_set_sign((EVP_PKEY_METHOD *)*param_2,(sign_init *)0x0,(sign *)0xdf8b1);
    EVP_PKEY_meth_set_verify((EVP_PKEY_METHOD *)*param_2,(verify_init *)0x0,(verify *)0xdf871);
    EVP_PKEY_meth_set_encrypt
              ((EVP_PKEY_METHOD *)*param_2,(encrypt_init *)0xdf545,(encryptfn *)0x114f25);
    EVP_PKEY_meth_set_decrypt((EVP_PKEY_METHOD *)*param_2,(decrypt_init *)0x0,(decrypt *)0x115165);
    EVP_PKEY_meth_set_derive((EVP_PKEY_METHOD *)*param_2,(derive_init *)0xdf549,(derive *)0x114ef5);
    EVP_PKEY_meth_set_paramgen
              ((EVP_PKEY_METHOD *)*param_2,(paramgen_init *)0xdf541,(paramgen *)0xdf9e9);
  }
  else {
    if (param_1 == 0x32f) {
      EVP_PKEY_meth_set_ctrl(pmeth,(ctrl *)0xdf641,(ctrl_str *)0xdfc81);
      EVP_PKEY_meth_set_signctx
                ((EVP_PKEY_METHOD *)*param_2,(signctx_init *)0xdf54d,(signctx *)0xdf61d);
      EVP_PKEY_meth_set_keygen((EVP_PKEY_METHOD *)*param_2,(keygen_init *)0x0,(keygen *)0xdf92d);
      EVP_PKEY_meth_set_init((EVP_PKEY_METHOD *)*param_2,(init *)0xdf5ed);
      EVP_PKEY_meth_set_cleanup((EVP_PKEY_METHOD *)*param_2,(cleanup *)0xdf56d);
      EVP_PKEY_meth_set_copy((EVP_PKEY_METHOD *)*param_2,(copy *)0xdfc31);
      return 1;
    }
    if (param_1 != 0x32b) {
      return 0;
    }
    EVP_PKEY_meth_set_ctrl(pmeth,(ctrl *)0xdf749,(ctrl_str *)0xdfb15);
    EVP_PKEY_meth_set_sign((EVP_PKEY_METHOD *)*param_2,(sign_init *)0x0,(sign *)0xdf82d);
    EVP_PKEY_meth_set_verify((EVP_PKEY_METHOD *)*param_2,(verify_init *)0x0,(verify *)0xdf7ed);
    EVP_PKEY_meth_set_keygen((EVP_PKEY_METHOD *)*param_2,(keygen_init *)0x0,(keygen *)0xdfdcd);
    EVP_PKEY_meth_set_encrypt
              ((EVP_PKEY_METHOD *)*param_2,(encrypt_init *)0xdf545,(encryptfn *)0x112005);
    EVP_PKEY_meth_set_decrypt((EVP_PKEY_METHOD *)*param_2,(decrypt_init *)0x0,(decrypt *)0x11226d);
    EVP_PKEY_meth_set_derive((EVP_PKEY_METHOD *)*param_2,(derive_init *)0xdf549,(derive *)0x111f99);
    EVP_PKEY_meth_set_paramgen
              ((EVP_PKEY_METHOD *)*param_2,(paramgen_init *)0xdf541,(paramgen *)0xdf999);
  }
  EVP_PKEY_meth_set_init((EVP_PKEY_METHOD *)*param_2,(init *)0xdf57d);
  EVP_PKEY_meth_set_cleanup((EVP_PKEY_METHOD *)*param_2,(cleanup *)0xdf551);
  EVP_PKEY_meth_set_copy((EVP_PKEY_METHOD *)*param_2,(copy *)0xdf8f5);
  return 1;
}

