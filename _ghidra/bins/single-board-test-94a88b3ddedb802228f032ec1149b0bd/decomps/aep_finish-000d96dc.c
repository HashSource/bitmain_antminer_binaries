
undefined4 aep_finish(void)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  
  if (aep_dso == (DSO *)0x0) {
    if (AEPHK_lib_error_code == 0) {
      AEPHK_lib_error_code = ERR_get_next_error_library();
    }
    ERR_put_error(AEPHK_lib_error_code,0x65,0x6f,"e_aep.c",0x219);
    uVar3 = 0;
  }
  else {
    iVar5 = 0;
    iVar4 = 0;
    iVar2 = 0;
    do {
      while (*(int *)(aep_app_conn_table + iVar2) != 1) {
        if (*(int *)(aep_app_conn_table + iVar2) == 2) {
          iVar5 = iVar5 + 1;
        }
        iVar2 = iVar2 + 8;
        iVar4 = iVar4 + 1;
        if (iVar2 == 0x800) goto LAB_000d9754;
      }
      HintPreloadData(iVar4 * 8 + 0x3b3d1c);
      iVar1 = (*p_AEP_CloseConnection)
                        (*(undefined4 *)(aep_app_conn_table + iVar2 + 4),
                         aep_app_conn_table + iVar4 * 8);
      if (iVar1 != 0) {
        if (AEPHK_lib_error_code == 0) {
          AEPHK_lib_error_code = ERR_get_next_error_library();
        }
        ERR_put_error(AEPHK_lib_error_code,0x65,0x65,"e_aep.c",0x21f);
        return 0;
      }
      *(undefined4 *)(aep_app_conn_table + iVar2) = 0;
      iVar1 = iVar2 + 8;
      *(undefined4 *)(aep_app_conn_table + iVar2 + 4) = 0;
      iVar4 = iVar4 + 1;
      iVar2 = iVar1;
    } while (iVar1 != 0x800);
LAB_000d9754:
    if (iVar5 == 0) {
      iVar2 = (*p_AEP_Finalize)();
      if (iVar2 == 0) {
        iVar2 = DSO_free(aep_dso);
        if (iVar2 == 0) {
          if (AEPHK_lib_error_code == 0) {
            AEPHK_lib_error_code = ERR_get_next_error_library();
          }
          ERR_put_error(AEPHK_lib_error_code,0x65,0x73,"e_aep.c",0x22e);
          uVar3 = 0;
        }
        else {
          uVar3 = 1;
          aep_dso = (DSO *)0x0;
          p_AEP_ModExp = 0;
          p_AEP_ModExpCrt = 0;
          p_AEP_Finalize = (code *)0x0;
          p_AEP_Initialize = 0;
          p_AEP_OpenConnection = 0;
          p_AEP_SetBNCallBacks = 0;
          p_AEP_CloseConnection = (code *)0x0;
        }
      }
      else {
        if (AEPHK_lib_error_code == 0) {
          AEPHK_lib_error_code = ERR_get_next_error_library();
        }
        ERR_put_error(AEPHK_lib_error_code,0x65,0x68,"e_aep.c",0x229);
        uVar3 = 0;
      }
    }
    else {
      if (AEPHK_lib_error_code == 0) {
        AEPHK_lib_error_code = ERR_get_next_error_library();
      }
      ERR_put_error(AEPHK_lib_error_code,0x65,0x66,"e_aep.c",0x223);
      uVar3 = 0;
    }
  }
  return uVar3;
}

