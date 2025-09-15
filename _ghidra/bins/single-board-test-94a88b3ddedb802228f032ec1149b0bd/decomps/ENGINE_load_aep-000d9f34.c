
void ENGINE_load_aep(void)

{
  ENGINE *e;
  int iVar1;
  RSA_METHOD *pRVar2;
  DSA_METHOD *pDVar3;
  DH_METHOD *pDVar4;
  
  e = ENGINE_new();
  if (e == (ENGINE *)0x0) {
    return;
  }
  iVar1 = ENGINE_set_id(e,"aep");
  if ((((((iVar1 != 0) && (iVar1 = ENGINE_set_name(e,"Aep hardware engine support"), iVar1 != 0)) &&
        (iVar1 = ENGINE_set_RSA(e,(RSA_METHOD *)aep_rsa), iVar1 != 0)) &&
       ((iVar1 = ENGINE_set_DSA(e,(DSA_METHOD *)aep_dsa), iVar1 != 0 &&
        (iVar1 = ENGINE_set_DH(e,(DH_METHOD *)aep_dh), iVar1 != 0)))) &&
      ((iVar1 = ENGINE_set_init_function(e,(ENGINE_GEN_INT_FUNC_PTR)0xd95b5), iVar1 != 0 &&
       ((iVar1 = ENGINE_set_destroy_function(e,(ENGINE_GEN_INT_FUNC_PTR)0xd94dd), iVar1 != 0 &&
        (iVar1 = ENGINE_set_finish_function(e,(ENGINE_GEN_INT_FUNC_PTR)0xd96dd), iVar1 != 0)))))) &&
     ((iVar1 = ENGINE_set_ctrl_function(e,(ENGINE_CTRL_FUNC_PTR)0xd9519), iVar1 != 0 &&
      (iVar1 = ENGINE_set_cmd_defns(e,(ENGINE_CMD_DEFN *)&aep_cmd_defns), iVar1 != 0)))) {
    pRVar2 = RSA_PKCS1_SSLeay();
    aep_rsa._4_4_ = pRVar2->rsa_pub_enc;
    aep_rsa._8_4_ = pRVar2->rsa_pub_dec;
    aep_rsa._12_4_ = pRVar2->rsa_priv_enc;
    aep_rsa._16_4_ = pRVar2->rsa_priv_dec;
    pDVar3 = DSA_OpenSSL();
    aep_dsa._4_4_ = pDVar3->dsa_do_sign;
    aep_dsa._8_4_ = pDVar3->dsa_sign_setup;
    aep_dsa._12_4_ = pDVar3->dsa_do_verify;
    pDVar3 = DSA_get_default_method();
    aep_dsa._0_4_ = pDVar3->name;
    aep_dsa._4_4_ = pDVar3->dsa_do_sign;
    aep_dsa._8_4_ = pDVar3->dsa_sign_setup;
    aep_dsa._12_4_ = pDVar3->dsa_do_verify;
    aep_dsa._24_4_ = pDVar3->init;
    aep_dsa._28_4_ = pDVar3->finish;
    aep_dsa._16_4_ = 0xd9c55;
    aep_dsa._32_4_ = pDVar3->flags;
    aep_dsa._36_4_ = pDVar3->app_data;
    aep_dsa._40_4_ = pDVar3->dsa_paramgen;
    aep_dsa._44_4_ = pDVar3->dsa_keygen;
    aep_dsa._20_4_ = 0xd9be1;
    pDVar4 = DH_OpenSSL();
    aep_dh._4_4_ = pDVar4->generate_key;
    aep_dh._8_4_ = pDVar4->compute_key;
    aep_dh._12_4_ = pDVar4->bn_mod_exp;
    if (AEPHK_lib_error_code == 0) {
      AEPHK_lib_error_code = ERR_get_next_error_library();
    }
    if (AEPHK_error_init != 0) {
      AEPHK_error_init = 0;
      ERR_load_strings(AEPHK_lib_error_code,(ERR_STRING_DATA *)AEPHK_str_functs);
      ERR_load_strings(AEPHK_lib_error_code,(ERR_STRING_DATA *)AEPHK_str_reasons);
    }
    ENGINE_add(e);
    ENGINE_free(e);
    ERR_clear_error();
    return;
  }
  ENGINE_free(e);
  return;
}

