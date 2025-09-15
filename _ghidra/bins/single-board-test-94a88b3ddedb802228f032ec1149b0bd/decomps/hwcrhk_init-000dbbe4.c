
undefined4 hwcrhk_init(void)

{
  DSO_FUNC_TYPE pDVar1;
  DSO_FUNC_TYPE pDVar2;
  DSO_FUNC_TYPE pDVar3;
  DSO_FUNC_TYPE pDVar4;
  DSO_FUNC_TYPE pDVar5;
  DSO_FUNC_TYPE pDVar6;
  DSO_FUNC_TYPE pDVar7;
  DSO_FUNC_TYPE pDVar8;
  DSO_FUNC_TYPE file;
  int iVar9;
  CRYPTO_dynlock_value *mode;
  CRYPTO_dynlock_value *l;
  int extraout_r0;
  char *filename;
  CRYPTO_dynlock_value *l_00;
  char *file_00;
  char *file_01;
  int line;
  int line_00;
  
  if (hwcrhk_dso == (DSO *)0x0) {
    filename = HWCRHK_LIBNAME;
    if (HWCRHK_LIBNAME == (char *)0x0) {
      filename = "nfhwcrhk";
    }
    hwcrhk_dso = DSO_load((DSO *)0x0,filename,(DSO_METHOD *)0x0,0);
    if (hwcrhk_dso == (DSO *)0x0) {
      if (HWCRHK_lib_error_code == 0) {
        HWCRHK_lib_error_code = ERR_get_next_error_library();
      }
      iVar9 = 0x22c;
    }
    else {
      pDVar1 = DSO_bind_func(hwcrhk_dso,"HWCryptoHook_Init");
      if (((((pDVar1 != (DSO_FUNC_TYPE)0x0) &&
            (pDVar2 = DSO_bind_func(hwcrhk_dso,"HWCryptoHook_Finish"), pDVar2 != (DSO_FUNC_TYPE)0x0)
            ) && (pDVar3 = DSO_bind_func(hwcrhk_dso,"HWCryptoHook_ModExp"),
                 pDVar3 != (DSO_FUNC_TYPE)0x0)) &&
          (((pDVar4 = DSO_bind_func(hwcrhk_dso,"HWCryptoHook_RSA"), pDVar4 != (DSO_FUNC_TYPE)0x0 &&
            (pDVar5 = DSO_bind_func(hwcrhk_dso,"HWCryptoHook_RSALoadKey"),
            pDVar5 != (DSO_FUNC_TYPE)0x0)) &&
           ((pDVar6 = DSO_bind_func(hwcrhk_dso,"HWCryptoHook_RSAGetPublicKey"),
            pDVar6 != (DSO_FUNC_TYPE)0x0 &&
            ((pDVar7 = DSO_bind_func(hwcrhk_dso,"HWCryptoHook_RSAUnloadKey"),
             pDVar7 != (DSO_FUNC_TYPE)0x0 &&
             (pDVar8 = DSO_bind_func(hwcrhk_dso,"HWCryptoHook_RandomBytes"),
             pDVar8 != (DSO_FUNC_TYPE)0x0)))))))) &&
         (file = DSO_bind_func(hwcrhk_dso,"HWCryptoHook_ModExpCRT"), file != (DSO_FUNC_TYPE)0x0)) {
        p_hwcrhk_RSAUnloadKey = pDVar7;
        p_hwcrhk_Init = pDVar1;
        p_hwcrhk_Finish = pDVar2;
        p_hwcrhk_ModExp = pDVar3;
        p_hwcrhk_RSA = pDVar4;
        p_hwcrhk_RSALoadKey = pDVar5;
        p_hwcrhk_RSAGetPublicKey = pDVar6;
        p_hwcrhk_RandomBytes = pDVar8;
        p_hwcrhk_ModExpCRT = file;
        if ((((disable_mutex_callbacks == 0) &&
             (mode = CRYPTO_get_dynlock_create_callback((char *)file,0),
             mode != (CRYPTO_dynlock_value *)0x0)) &&
            (CRYPTO_get_dynlock_lock_callback((int)mode,l_00,file_01,line_00),
            l != (CRYPTO_dynlock_value *)0x0)) &&
           (CRYPTO_get_dynlock_destroy_callback(l,file_00,line), extraout_r0 != 0)) {
          hwcrhk_globals._32_4_ = 0xdbb4d;
          hwcrhk_globals._36_4_ = 0xdbaed;
          hwcrhk_globals._40_4_ = 0xdbad9;
          hwcrhk_globals._44_4_ = 0xdbb45;
        }
        iVar9 = get_context_constprop_2();
        if (iVar9 != 0) {
          if (hndidx_rsa == -1) {
            hndidx_rsa = RSA_get_ex_new_index
                                   (0,"nFast HWCryptoHook RSA key handle",(undefined1 *)0x0,
                                    (undefined1 *)0x0,(undefined1 *)0x0);
            return 1;
          }
          return 1;
        }
        if (HWCRHK_lib_error_code == 0) {
          HWCRHK_lib_error_code = ERR_get_next_error_library();
        }
        ERR_put_error(HWCRHK_lib_error_code,0x67,0x71,"e_chil.c",0x266);
        goto LAB_000dbc06;
      }
      if (HWCRHK_lib_error_code == 0) {
        HWCRHK_lib_error_code = ERR_get_next_error_library();
      }
      iVar9 = 0x243;
    }
    ERR_put_error(HWCRHK_lib_error_code,0x67,0x68,"e_chil.c",iVar9);
  }
  else {
    if (HWCRHK_lib_error_code == 0) {
      HWCRHK_lib_error_code = ERR_get_next_error_library();
    }
    ERR_put_error(HWCRHK_lib_error_code,0x67,100,"e_chil.c",0x226);
  }
LAB_000dbc06:
  if (hwcrhk_dso != (DSO *)0x0) {
    DSO_free(hwcrhk_dso);
  }
  p_hwcrhk_ModExpCRT = (DSO_FUNC_TYPE)0x0;
  p_hwcrhk_RandomBytes = (DSO_FUNC_TYPE)0x0;
  p_hwcrhk_RSAGetPublicKey = (DSO_FUNC_TYPE)0x0;
  p_hwcrhk_RSALoadKey = (DSO_FUNC_TYPE)0x0;
  p_hwcrhk_RSA = (DSO_FUNC_TYPE)0x0;
  p_hwcrhk_ModExp = (DSO_FUNC_TYPE)0x0;
  p_hwcrhk_Finish = (DSO_FUNC_TYPE)0x0;
  hwcrhk_dso = (DSO *)0x0;
  p_hwcrhk_Init = (DSO_FUNC_TYPE)0x0;
  p_hwcrhk_RSAUnloadKey = (DSO_FUNC_TYPE)0x0;
  return 0;
}

