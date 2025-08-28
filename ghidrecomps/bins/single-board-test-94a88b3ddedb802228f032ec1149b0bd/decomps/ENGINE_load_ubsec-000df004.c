
void ENGINE_load_ubsec(void)

{
  ENGINE *e;
  int iVar1;
  RSA_METHOD *pRVar2;
  DH_METHOD *pDVar3;
  
  e = ENGINE_new();
  if (e == (ENGINE *)0x0) {
    return;
  }
  iVar1 = ENGINE_set_id(e,"ubsec");
  if ((((((iVar1 != 0) && (iVar1 = ENGINE_set_name(e,"UBSEC hardware engine support"), iVar1 != 0))
        && (iVar1 = ENGINE_set_RSA(e,(RSA_METHOD *)ubsec_rsa), iVar1 != 0)) &&
       ((iVar1 = ENGINE_set_DSA(e,(DSA_METHOD *)ubsec_dsa), iVar1 != 0 &&
        (iVar1 = ENGINE_set_DH(e,(DH_METHOD *)ubsec_dh), iVar1 != 0)))) &&
      ((iVar1 = ENGINE_set_destroy_function(e,(ENGINE_GEN_INT_FUNC_PTR)0xde255), iVar1 != 0 &&
       ((iVar1 = ENGINE_set_init_function(e,(ENGINE_GEN_INT_FUNC_PTR)0xde335), iVar1 != 0 &&
        (iVar1 = ENGINE_set_finish_function(e,(ENGINE_GEN_INT_FUNC_PTR)0xdef7d), iVar1 != 0)))))) &&
     ((iVar1 = ENGINE_set_ctrl_function(e,(ENGINE_CTRL_FUNC_PTR)0xde299), iVar1 != 0 &&
      (iVar1 = ENGINE_set_cmd_defns(e,(ENGINE_CMD_DEFN *)&ubsec_cmd_defns), iVar1 != 0)))) {
    pRVar2 = RSA_PKCS1_SSLeay();
    ubsec_rsa._4_4_ = pRVar2->rsa_pub_enc;
    ubsec_rsa._8_4_ = pRVar2->rsa_pub_dec;
    ubsec_rsa._12_4_ = pRVar2->rsa_priv_enc;
    ubsec_rsa._16_4_ = pRVar2->rsa_priv_dec;
    pDVar3 = DH_OpenSSL();
    ubsec_dh._4_4_ = pDVar3->generate_key;
    ubsec_dh._8_4_ = pDVar3->compute_key;
    if (UBSEC_lib_error_code == 0) {
      UBSEC_lib_error_code = ERR_get_next_error_library();
    }
    if (UBSEC_error_init != 0) {
      UBSEC_error_init = 0;
      ERR_load_strings(UBSEC_lib_error_code,(ERR_STRING_DATA *)UBSEC_str_functs);
      ERR_load_strings(UBSEC_lib_error_code,(ERR_STRING_DATA *)UBSEC_str_reasons);
      UBSEC_lib_name._0_4_ = UBSEC_lib_error_code << 0x18;
      ERR_load_strings(0,(ERR_STRING_DATA *)UBSEC_lib_name);
    }
    ENGINE_add(e);
    ENGINE_free(e);
    ERR_clear_error();
    return;
  }
  ENGINE_free(e);
  return;
}

