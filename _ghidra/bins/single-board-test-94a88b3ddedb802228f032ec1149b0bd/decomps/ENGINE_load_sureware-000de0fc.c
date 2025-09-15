
void ENGINE_load_sureware(void)

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
  iVar1 = ENGINE_set_id(e,"sureware");
  if (((((iVar1 != 0) && (iVar1 = ENGINE_set_name(e,"SureWare hardware engine support"), iVar1 != 0)
        ) && (iVar1 = ENGINE_set_RSA(e,(RSA_METHOD *)surewarehk_rsa), iVar1 != 0)) &&
      ((((iVar1 = ENGINE_set_DSA(e,(DSA_METHOD *)surewarehk_dsa), iVar1 != 0 &&
         (iVar1 = ENGINE_set_DH(e,(DH_METHOD *)surewarehk_dh), iVar1 != 0)) &&
        ((iVar1 = ENGINE_set_RAND(e,(RAND_METHOD *)surewarehk_rand), iVar1 != 0 &&
         ((iVar1 = ENGINE_set_destroy_function(e,(ENGINE_GEN_INT_FUNC_PTR)0xdd109), iVar1 != 0 &&
          (iVar1 = ENGINE_set_init_function(e,(ENGINE_GEN_INT_FUNC_PTR)0xdd7ad), iVar1 != 0)))))) &&
       (iVar1 = ENGINE_set_finish_function(e,(ENGINE_GEN_INT_FUNC_PTR)0xddd39), iVar1 != 0)))) &&
     (((iVar1 = ENGINE_set_ctrl_function(e,(ENGINE_CTRL_FUNC_PTR)0xdda71), iVar1 != 0 &&
       (iVar1 = ENGINE_set_load_privkey_function(e,(ENGINE_LOAD_KEY_PTR)0xdd6e5), iVar1 != 0)) &&
      (iVar1 = ENGINE_set_load_pubkey_function(e,(ENGINE_LOAD_KEY_PTR)0xdd625), iVar1 != 0)))) {
    pRVar2 = RSA_PKCS1_SSLeay();
    if (pRVar2 != (RSA_METHOD *)0x0) {
      surewarehk_rsa._4_4_ = pRVar2->rsa_pub_enc;
      surewarehk_rsa._8_4_ = pRVar2->rsa_pub_dec;
    }
    pDVar3 = DSA_OpenSSL();
    if (pDVar3 != (DSA_METHOD *)0x0) {
      surewarehk_dsa._12_4_ = pDVar3->dsa_do_verify;
    }
    pDVar4 = DH_OpenSSL();
    if (pDVar4 != (DH_METHOD *)0x0) {
      surewarehk_dh._4_4_ = pDVar4->generate_key;
      surewarehk_dh._8_4_ = pDVar4->compute_key;
    }
    if (SUREWARE_lib_error_code == 0) {
      SUREWARE_lib_error_code = ERR_get_next_error_library();
    }
    if (SUREWARE_error_init != 0) {
      SUREWARE_error_init = 0;
      ERR_load_strings(SUREWARE_lib_error_code,(ERR_STRING_DATA *)SUREWARE_str_functs);
      ERR_load_strings(SUREWARE_lib_error_code,(ERR_STRING_DATA *)SUREWARE_str_reasons);
      SUREWARE_lib_name._0_4_ = SUREWARE_lib_error_code << 0x18;
      ERR_load_strings(0,(ERR_STRING_DATA *)SUREWARE_lib_name);
    }
    ENGINE_add(e);
    ENGINE_free(e);
    ERR_clear_error();
    return;
  }
  ENGINE_free(e);
  return;
}

