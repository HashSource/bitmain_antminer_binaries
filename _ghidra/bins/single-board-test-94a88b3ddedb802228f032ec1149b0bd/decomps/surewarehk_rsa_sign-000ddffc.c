
int surewarehk_rsa_sign(undefined4 param_1,undefined4 param_2,undefined4 param_3,RSA *param_4,
                       int param_5)

{
  void *pvVar1;
  int iVar2;
  int local_64;
  char local_60 [64];
  
  local_60[0x10] = '\0';
  local_60[0x11] = '\0';
  local_60[0x12] = '\0';
  local_60[0x13] = '\0';
  local_60[0x14] = '\0';
  local_60[0x15] = '\0';
  local_60[0x16] = '\0';
  local_60[0x17] = '\0';
  local_60[0x18] = '\0';
  local_60[0x19] = '\0';
  local_60[0x1a] = '\0';
  local_60[0x1b] = '\0';
  local_60[0x1c] = '\0';
  local_60[0x1d] = '\0';
  local_60[0x1e] = '\0';
  local_60[0x1f] = '\0';
  local_60[0x20] = '\0';
  local_60[0x21] = '\0';
  local_60[0x22] = '\0';
  local_60[0x23] = '\0';
  local_60[0x24] = '\0';
  local_60[0x25] = '\0';
  local_60[0x26] = '\0';
  local_60[0x27] = '\0';
  local_60[0x28] = '\0';
  local_60[0x29] = '\0';
  local_60[0x2a] = '\0';
  local_60[0x2b] = '\0';
  local_60[0x2c] = '\0';
  local_60[0x2d] = '\0';
  local_60[0x2e] = '\0';
  local_60[0x2f] = '\0';
  local_60[0x30] = '\0';
  local_60[0x31] = '\0';
  local_60[0x32] = '\0';
  local_60[0x33] = '\0';
  local_60[0x34] = '\0';
  local_60[0x35] = '\0';
  local_60[0x36] = '\0';
  local_60[0x37] = '\0';
  local_60[0x38] = '\0';
  local_60[0x39] = '\0';
  local_60[0x3a] = '\0';
  local_60[0x3b] = '\0';
  local_60[0x3c] = '\0';
  local_60[0x3d] = '\0';
  local_60[0x3e] = '\0';
  local_60[0x3f] = '\0';
  builtin_strncpy(local_60,"ENGINE_rsa_sign",0x10);
  if (p_surewarehk_Rsa_Sign == (code *)0x0) {
    if (SUREWARE_lib_error_code == 0) {
      SUREWARE_lib_error_code = ERR_get_next_error_library();
    }
    ERR_put_error(SUREWARE_lib_error_code,0x6f,0x75,"e_sureware.c",0x3df);
  }
  else {
    pvVar1 = RSA_get_ex_data(param_4,rsaHndidx);
    if (pvVar1 == (void *)0x0) {
      if (SUREWARE_lib_error_code == 0) {
        SUREWARE_lib_error_code = ERR_get_next_error_library();
      }
      ERR_put_error(SUREWARE_lib_error_code,0x6f,0x69,"e_sureware.c",0x3e4);
    }
    else {
      if (param_5 == 1) {
        iVar2 = (*p_surewarehk_Rsa_Sign)(local_60,param_1,param_2,&local_64,param_3,pvVar1,1);
        surewarehk_error_handling(local_60,0x6f,iVar2);
        if (iVar2 != 1) {
          return iVar2;
        }
        return local_64;
      }
      if (SUREWARE_lib_error_code == 0) {
        SUREWARE_lib_error_code = ERR_get_next_error_library();
      }
      ERR_put_error(SUREWARE_lib_error_code,0x6f,0x6b,"e_sureware.c",0x3f1);
    }
  }
  return 0;
}

