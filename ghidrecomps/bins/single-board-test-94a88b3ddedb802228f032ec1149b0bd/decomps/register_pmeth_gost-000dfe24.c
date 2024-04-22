
undefined4 register_pmeth_gost(int param_1,EVP_PKEY_METHOD **param_2,int param_3)

{
  EVP_PKEY_METHOD *pmeth;
  
  pmeth = EVP_PKEY_meth_new(param_1,param_3);
  *param_2 = pmeth;
  if (pmeth == (EVP_PKEY_METHOD *)0x0) {
    return 0;
  }
  if (param_1 == 0x32c) {
    EVP_PKEY_meth_set_ctrl(pmeth,DAT_000dff60,DAT_000dff64);
    EVP_PKEY_meth_set_keygen(*param_2,(keygen_init *)0x0,DAT_000dff68);
    EVP_PKEY_meth_set_sign(*param_2,(sign_init *)0x0,DAT_000dff6c);
    EVP_PKEY_meth_set_verify(*param_2,(verify_init *)0x0,DAT_000dff70);
    EVP_PKEY_meth_set_encrypt(*param_2,DAT_000dff74,DAT_000dff78);
    EVP_PKEY_meth_set_decrypt(*param_2,(decrypt_init *)0x0,DAT_000dff7c);
    EVP_PKEY_meth_set_derive(*param_2,DAT_000dff80,DAT_000dff84);
    EVP_PKEY_meth_set_paramgen(*param_2,DAT_000dff88,DAT_000dff8c);
  }
  else {
    if (param_1 == 0x32f) {
      EVP_PKEY_meth_set_ctrl(pmeth,DAT_000dff40,DAT_000dff44);
      EVP_PKEY_meth_set_signctx(*param_2,DAT_000dff48,DAT_000dff4c);
      EVP_PKEY_meth_set_keygen(*param_2,(keygen_init *)0x0,DAT_000dff50);
      EVP_PKEY_meth_set_init(*param_2,DAT_000dff54);
      EVP_PKEY_meth_set_cleanup(*param_2,DAT_000dff58);
      EVP_PKEY_meth_set_copy(*param_2,DAT_000dff5c);
      return 1;
    }
    if (param_1 != 0x32b) {
      return 0;
    }
    EVP_PKEY_meth_set_ctrl(pmeth,DAT_000dff60,DAT_000dff9c);
    EVP_PKEY_meth_set_sign(*param_2,(sign_init *)0x0,DAT_000dffa0);
    EVP_PKEY_meth_set_verify(*param_2,(verify_init *)0x0,DAT_000dffa4);
    EVP_PKEY_meth_set_keygen(*param_2,(keygen_init *)0x0,DAT_000dffa8);
    EVP_PKEY_meth_set_encrypt(*param_2,DAT_000dff74,DAT_000dffac);
    EVP_PKEY_meth_set_decrypt(*param_2,(decrypt_init *)0x0,DAT_000dffb0);
    EVP_PKEY_meth_set_derive(*param_2,DAT_000dff80,DAT_000dffb4);
    EVP_PKEY_meth_set_paramgen(*param_2,DAT_000dff88,DAT_000dffb8);
  }
  EVP_PKEY_meth_set_init(*param_2,DAT_000dff90);
  EVP_PKEY_meth_set_cleanup(*param_2,DAT_000dff94);
  EVP_PKEY_meth_set_copy(*param_2,DAT_000dff98);
  return 1;
}

