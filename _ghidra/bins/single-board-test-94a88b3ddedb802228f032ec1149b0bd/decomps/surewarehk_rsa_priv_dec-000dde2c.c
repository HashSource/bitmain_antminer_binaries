
size_t surewarehk_rsa_priv_dec
                 (int param_1,undefined4 param_2,uchar *param_3,RSA *param_4,int param_5)

{
  void *pvVar1;
  size_t sVar2;
  uchar *f;
  size_t local_6c;
  char local_68 [68];
  
  local_68[0x14] = '\0';
  local_68[0x15] = '\0';
  local_68[0x16] = '\0';
  local_68[0x17] = '\0';
  builtin_strncpy(local_68,"ENGINE_rsa_priv_dec",0x14);
  local_68[0x18] = '\0';
  local_68[0x19] = '\0';
  local_68[0x1a] = '\0';
  local_68[0x1b] = '\0';
  local_68[0x1c] = '\0';
  local_68[0x1d] = '\0';
  local_68[0x1e] = '\0';
  local_68[0x1f] = '\0';
  local_68[0x20] = '\0';
  local_68[0x21] = '\0';
  local_68[0x22] = '\0';
  local_68[0x23] = '\0';
  local_68[0x24] = '\0';
  local_68[0x25] = '\0';
  local_68[0x26] = '\0';
  local_68[0x27] = '\0';
  local_68[0x28] = '\0';
  local_68[0x29] = '\0';
  local_68[0x2a] = '\0';
  local_68[0x2b] = '\0';
  local_68[0x2c] = '\0';
  local_68[0x2d] = '\0';
  local_68[0x2e] = '\0';
  local_68[0x2f] = '\0';
  local_68[0x30] = '\0';
  local_68[0x31] = '\0';
  local_68[0x32] = '\0';
  local_68[0x33] = '\0';
  local_68[0x34] = '\0';
  local_68[0x35] = '\0';
  local_68[0x36] = '\0';
  local_68[0x37] = '\0';
  local_68[0x38] = '\0';
  local_68[0x39] = '\0';
  local_68[0x3a] = '\0';
  local_68[0x3b] = '\0';
  local_68[0x3c] = '\0';
  local_68[0x3d] = '\0';
  local_68[0x3e] = '\0';
  local_68[0x3f] = '\0';
  if (p_surewarehk_Rsa_Priv_Dec == (code *)0x0) {
    if (SUREWARE_lib_error_code == 0) {
      SUREWARE_lib_error_code = ERR_get_next_error_library();
    }
    ERR_put_error(SUREWARE_lib_error_code,0x6e,0x75,"e_sureware.c",0x38f);
    pvVar1 = (void *)0x0;
  }
  else {
    pvVar1 = RSA_get_ex_data(param_4,rsaHndidx);
    if (pvVar1 == (void *)0x0) {
      if (SUREWARE_lib_error_code == 0) {
        SUREWARE_lib_error_code = ERR_get_next_error_library();
      }
      ERR_put_error(SUREWARE_lib_error_code,0x6e,0x69,"e_sureware.c",0x394);
      return 0;
    }
  }
  if (param_5 == 1) {
    sVar2 = (*p_surewarehk_Rsa_Priv_Dec)(local_68,param_1,param_2,&local_6c,param_3,pvVar1,1);
    surewarehk_error_handling(local_68,0x6e,sVar2);
    if (sVar2 != 1) {
      return sVar2;
    }
    return local_6c;
  }
  sVar2 = (*p_surewarehk_Rsa_Priv_Dec)(local_68,param_1,param_2,&local_6c,param_3,pvVar1,0);
  surewarehk_error_handling(local_68,0x6e,sVar2);
  if (sVar2 != 1) {
    return sVar2;
  }
  f = (uchar *)CRYPTO_malloc(local_6c,"e_sureware.c",0x3ac);
  if (f == (uchar *)0x0) {
    if (SUREWARE_lib_error_code == 0) {
      SUREWARE_lib_error_code = ERR_get_next_error_library();
    }
    ERR_put_error(SUREWARE_lib_error_code,0x6e,0x41,"e_sureware.c",0x3ae);
    return 1;
  }
  memcpy(f,param_3,local_6c);
  if (param_5 == 3) {
    sVar2 = RSA_padding_check_none(param_3,local_6c,f,param_1,local_6c);
  }
  else if (param_5 == 4) {
    sVar2 = RSA_padding_check_PKCS1_OAEP(param_3,local_6c,f,local_6c,local_6c,(uchar *)0x0,0);
  }
  else {
    if (param_5 != 2) {
      if (SUREWARE_lib_error_code == 0) {
        SUREWARE_lib_error_code = ERR_get_next_error_library();
      }
      ERR_put_error(SUREWARE_lib_error_code,0x6e,0x6b,"e_sureware.c",0x3c6);
      sVar2 = 1;
      goto LAB_000ddf3e;
    }
    sVar2 = RSA_padding_check_SSLv23(param_3,local_6c,f,param_1,local_6c);
  }
  if ((int)sVar2 < 0) {
    if (SUREWARE_lib_error_code == 0) {
      SUREWARE_lib_error_code = ERR_get_next_error_library();
    }
    ERR_put_error(SUREWARE_lib_error_code,0x6e,0x6a,"e_sureware.c",0x3cb);
  }
LAB_000ddf3e:
  OPENSSL_cleanse(f,local_6c);
  CRYPTO_free(f);
  return sVar2;
}

