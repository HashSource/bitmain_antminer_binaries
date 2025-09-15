
int aep_get_connection(undefined4 *param_1)

{
  __pid_t _Var1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  
  CRYPTO_lock(9,0x1e,"e_aep.c",0x36a);
  _Var1 = getpid();
  if (recorded_pid == _Var1) {
    iVar2 = 0;
    do {
      iVar4 = iVar2 * 8;
      iVar3 = iVar2 * 8;
      iVar2 = iVar2 + 1;
      if (*(int *)(aep_app_conn_table + iVar4) == 1) {
        iVar2 = 0;
        *(undefined4 *)(aep_app_conn_table + iVar3) = 2;
        *param_1 = *(undefined4 *)(aep_app_conn_table + iVar3 + 4);
        goto LAB_000d98e2;
      }
    } while (iVar2 != 0x100);
    iVar2 = 0;
    do {
      iVar4 = iVar2 * 8;
      iVar3 = iVar2 * 8;
      iVar2 = iVar2 + 1;
      if (*(int *)(aep_app_conn_table + iVar4) == 0) {
        iVar2 = (*p_AEP_OpenConnection)(param_1);
        if (iVar2 == 0) {
          uVar5 = *param_1;
          *(undefined4 *)(aep_app_conn_table + iVar3) = 2;
          *(undefined4 *)(aep_app_conn_table + iVar3 + 4) = uVar5;
        }
        else {
          if (AEPHK_lib_error_code == 0) {
            AEPHK_lib_error_code = ERR_get_next_error_library();
          }
          ERR_put_error(AEPHK_lib_error_code,0x66,0x73,"e_aep.c",0x3c9);
        }
        goto LAB_000d98e2;
      }
    } while (iVar2 != 0x100);
    iVar2 = 0x10000001;
  }
  else {
    recorded_pid = _Var1;
    (*p_AEP_Finalize)();
    iVar2 = (*p_AEP_Initialize)(0);
    if (iVar2 == 0) {
      iVar2 = (*p_AEP_SetBNCallBacks)(0xd92f5,0xd9301,0xd9489);
      if (iVar2 == 0) {
        do {
          *(undefined4 *)(aep_app_conn_table + iVar2) = 0;
          iVar4 = iVar2 + 8;
          *(undefined4 *)(aep_app_conn_table + iVar2 + 4) = 0;
          iVar2 = iVar4;
        } while (iVar4 != 0x800);
        iVar2 = (*p_AEP_OpenConnection)(param_1);
        if (iVar2 == 0) {
          aep_app_conn_table._4_4_ = *param_1;
          aep_app_conn_table._0_4_ = 2;
        }
        else {
          if (AEPHK_lib_error_code == 0) {
            AEPHK_lib_error_code = ERR_get_next_error_library();
          }
          ERR_put_error(AEPHK_lib_error_code,0x66,0x73,"e_aep.c",0x3aa);
          recorded_pid = 0;
        }
      }
      else {
        if (AEPHK_lib_error_code == 0) {
          AEPHK_lib_error_code = ERR_get_next_error_library();
        }
        ERR_put_error(AEPHK_lib_error_code,0x66,0x72,"e_aep.c",0x391);
        recorded_pid = 0;
      }
    }
    else {
      if (AEPHK_lib_error_code == 0) {
        AEPHK_lib_error_code = ERR_get_next_error_library();
      }
      ERR_put_error(AEPHK_lib_error_code,0x66,0x6b,"e_aep.c",900);
      recorded_pid = 0;
    }
  }
LAB_000d98e2:
  CRYPTO_lock(10,0x1e,"e_aep.c",0x3d4);
  return iVar2;
}

