
undefined4 aep_finish(void)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  
  if (aep_dso == 0) {
    if (AEPHK_lib_error_code == 0) {
      AEPHK_lib_error_code = ERR_get_next_error_library();
    }
    ERR_put_error(AEPHK_lib_error_code,0x65,0x6f,DAT_000d9850,0x219);
    uVar2 = 0;
  }
  else {
    iVar6 = 0;
    iVar5 = 0;
    iVar3 = 0;
    do {
      while (iVar4 = DAT_000d984c, *(int *)(aep_app_conn_table + iVar3) == 1) {
        HintPreloadData(iVar5 * 8 + 0x3b3d1c);
        iVar1 = (*p_AEP_CloseConnection)
                          (*(undefined4 *)(aep_app_conn_table + iVar3 + 4),
                           aep_app_conn_table + iVar5 * 8);
        if (iVar1 != 0) {
          iVar3 = *(int *)(iVar4 + 4);
          if (iVar3 == 0) {
            iVar3 = ERR_get_next_error_library();
            *(int *)(iVar4 + 4) = iVar3;
          }
          ERR_put_error(iVar3,0x65,0x65,DAT_000d9850,0x21f);
          return 0;
        }
        *(undefined4 *)(aep_app_conn_table + iVar3) = 0;
        iVar4 = iVar3 + 8;
        *(undefined4 *)(aep_app_conn_table + iVar3 + 4) = 0;
        iVar5 = iVar5 + 1;
        iVar3 = iVar4;
        if (iVar4 == 0x800) goto LAB_000d9754;
      }
      if (*(int *)(aep_app_conn_table + iVar3) == 2) {
        iVar6 = iVar6 + 1;
      }
      iVar3 = iVar3 + 8;
      iVar5 = iVar5 + 1;
    } while (iVar3 != 0x800);
LAB_000d9754:
    iVar3 = DAT_000d984c;
    if (iVar6 == 0) {
      iVar5 = (*p_AEP_Finalize)();
      if (iVar5 == 0) {
        iVar5 = DSO_free(*(DSO **)(iVar3 + 8));
        if (iVar5 == 0) {
          iVar5 = *(int *)(iVar3 + 4);
          if (iVar5 == 0) {
            iVar5 = ERR_get_next_error_library();
            *(int *)(iVar3 + 4) = iVar5;
          }
          ERR_put_error(iVar5,0x65,0x73,DAT_000d9850,0x22e);
          uVar2 = 0;
        }
        else {
          uVar2 = 1;
          *(undefined4 *)(iVar3 + 8) = 0;
          *(undefined4 *)(iVar3 + 0x24) = 0;
          *(undefined4 *)(iVar3 + 0x1c) = 0;
          *(undefined4 *)(iVar3 + 0xc) = 0;
          *(undefined4 *)(iVar3 + 0x10) = 0;
          *(undefined4 *)(iVar3 + 0x18) = 0;
          *(undefined4 *)(iVar3 + 0x14) = 0;
          *(undefined4 *)(iVar3 + 0x20) = 0;
        }
      }
      else {
        iVar5 = *(int *)(iVar3 + 4);
        if (iVar5 == 0) {
          iVar5 = ERR_get_next_error_library();
          *(int *)(iVar3 + 4) = iVar5;
        }
        ERR_put_error(iVar5,0x65,0x68,DAT_000d9850,0x229);
        uVar2 = 0;
      }
    }
    else {
      iVar5 = AEPHK_lib_error_code;
      if (AEPHK_lib_error_code == 0) {
        iVar5 = ERR_get_next_error_library();
        *(int *)(iVar3 + 4) = iVar5;
      }
      ERR_put_error(iVar5,0x65,0x66,DAT_000d9850,0x223);
      uVar2 = 0;
    }
  }
  return uVar2;
}

