
int aep_mod_exp_part_0(BIGNUM *param_1,BIGNUM *param_2,BIGNUM *param_3,BIGNUM *param_4,
                      BN_CTX *param_5)

{
  int iVar1;
  int iVar2;
  int local_2c [2];
  
  iVar1 = aep_get_connection(local_2c);
  if (iVar1 == 0) {
    iVar1 = (*p_AEP_ModExp)(local_2c[0],param_2,param_3,param_4,param_1,0);
    if (iVar1 == 0) {
      CRYPTO_lock(9,0x1e,"e_aep.c",0x3dc);
      iVar1 = 0;
      do {
        iVar2 = iVar1 * 8;
        iVar1 = iVar1 + 1;
        if (local_2c[0] == *(int *)(aep_app_conn_table + iVar2 + 4)) {
          *(undefined4 *)(aep_app_conn_table + iVar2) = 1;
          break;
        }
      } while (iVar1 != 0x100);
      CRYPTO_lock(10,0x1e,"e_aep.c",1000);
      return 1;
    }
    if (AEPHK_lib_error_code == 0) {
      AEPHK_lib_error_code = ERR_get_next_error_library();
    }
    iVar1 = 0;
    ERR_put_error(AEPHK_lib_error_code,0x68,0x6e,"e_aep.c",0x279);
    CRYPTO_lock(9,0x1e,"e_aep.c",0x3f2);
    do {
      iVar2 = iVar1 * 8;
      iVar1 = iVar1 + 1;
      if (local_2c[0] == *(int *)(aep_app_conn_table + iVar2 + 4)) {
        iVar1 = (*p_AEP_CloseConnection)(local_2c[0]);
        if (iVar1 == 0) {
          *(undefined4 *)(aep_app_conn_table + iVar2) = 0;
          *(undefined4 *)(aep_app_conn_table + iVar2 + 4) = 0;
        }
        break;
      }
    } while (iVar1 != 0x100);
    CRYPTO_lock(10,0x1e,"e_aep.c",0x403);
  }
  else {
    if (AEPHK_lib_error_code == 0) {
      AEPHK_lib_error_code = ERR_get_next_error_library();
    }
    ERR_put_error(AEPHK_lib_error_code,0x68,0x69,"e_aep.c",0x26e);
  }
  iVar1 = BN_mod_exp(param_1,param_2,param_3,param_4,param_5);
  return iVar1;
}

