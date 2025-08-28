
void ENGINE_load_chil(void)

{
  ENGINE *e;
  int iVar1;
  RSA_METHOD *pRVar2;
  DH_METHOD *pDVar3;
  
  e = ENGINE_new();
  if (e == (ENGINE *)0x0) {
    return;
  }
  iVar1 = ENGINE_set_id(e,"chil");
  if (((((iVar1 != 0) && (iVar1 = ENGINE_set_name(e,"CHIL hardware engine support"), iVar1 != 0)) &&
       (iVar1 = ENGINE_set_RSA(e,(RSA_METHOD *)hwcrhk_rsa), iVar1 != 0)) &&
      ((((iVar1 = ENGINE_set_DH(e,(DH_METHOD *)hwcrhk_dh), iVar1 != 0 &&
         (iVar1 = ENGINE_set_RAND(e,(RAND_METHOD *)hwcrhk_rand), iVar1 != 0)) &&
        ((iVar1 = ENGINE_set_destroy_function(e,(ENGINE_GEN_INT_FUNC_PTR)0xdbb9d), iVar1 != 0 &&
         ((iVar1 = ENGINE_set_init_function(e,(ENGINE_GEN_INT_FUNC_PTR)0xdbbe5), iVar1 != 0 &&
          (iVar1 = ENGINE_set_finish_function(e,(ENGINE_GEN_INT_FUNC_PTR)0xdc21d), iVar1 != 0))))))
       && (iVar1 = ENGINE_set_ctrl_function(e,(ENGINE_CTRL_FUNC_PTR)0xdc549), iVar1 != 0)))) &&
     (((iVar1 = ENGINE_set_load_privkey_function(e,(ENGINE_LOAD_KEY_PTR)0xdc779), iVar1 != 0 &&
       (iVar1 = ENGINE_set_load_pubkey_function(e,(ENGINE_LOAD_KEY_PTR)0xdc9c1), iVar1 != 0)) &&
      (iVar1 = ENGINE_set_cmd_defns(e,(ENGINE_CMD_DEFN *)&hwcrhk_cmd_defns), iVar1 != 0)))) {
    pRVar2 = RSA_PKCS1_SSLeay();
    hwcrhk_rsa._4_4_ = pRVar2->rsa_pub_enc;
    hwcrhk_rsa._8_4_ = pRVar2->rsa_pub_dec;
    hwcrhk_rsa._12_4_ = pRVar2->rsa_priv_enc;
    hwcrhk_rsa._16_4_ = pRVar2->rsa_priv_dec;
    pDVar3 = DH_OpenSSL();
    hwcrhk_dh._4_4_ = pDVar3->generate_key;
    hwcrhk_dh._8_4_ = pDVar3->compute_key;
    if (HWCRHK_lib_error_code == 0) {
      HWCRHK_lib_error_code = ERR_get_next_error_library();
    }
    if (HWCRHK_error_init != 0) {
      HWCRHK_error_init = 0;
      ERR_load_strings(HWCRHK_lib_error_code,(ERR_STRING_DATA *)HWCRHK_str_functs);
      ERR_load_strings(HWCRHK_lib_error_code,(ERR_STRING_DATA *)HWCRHK_str_reasons);
      HWCRHK_lib_name._0_4_ = HWCRHK_lib_error_code << 0x18;
      ERR_load_strings(0,(ERR_STRING_DATA *)HWCRHK_lib_name);
    }
    ENGINE_add(e);
    ENGINE_free(e);
    ERR_clear_error();
    return;
  }
  ENGINE_free(e);
  return;
}

