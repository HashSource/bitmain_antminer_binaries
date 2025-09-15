
undefined4 hwcrhk_finish(void)

{
  int iVar1;
  undefined4 uVar2;
  
  if (HWCRHK_LIBNAME != (void *)0x0) {
    CRYPTO_free(HWCRHK_LIBNAME);
  }
  HWCRHK_LIBNAME = (void *)0x0;
  if (hwcrhk_dso == (DSO *)0x0) {
    if (HWCRHK_lib_error_code == 0) {
      HWCRHK_lib_error_code = ERR_get_next_error_library();
    }
    uVar2 = 0;
    ERR_put_error(HWCRHK_lib_error_code,0x65,0x6b,"e_chil.c",0x288);
  }
  else {
    (*p_hwcrhk_Finish)(hwcrhk_context);
    iVar1 = DSO_free(hwcrhk_dso);
    if (iVar1 == 0) {
      if (HWCRHK_lib_error_code == 0) {
        HWCRHK_lib_error_code = ERR_get_next_error_library();
      }
      uVar2 = 0;
      ERR_put_error(HWCRHK_lib_error_code,0x65,0x68,"e_chil.c",0x28e);
    }
    else {
      uVar2 = 1;
    }
  }
  if (logstream != (BIO *)0x0) {
    BIO_free(logstream);
  }
  hwcrhk_dso = (DSO *)0x0;
  p_hwcrhk_Init = 0;
  p_hwcrhk_Finish = (code *)0x0;
  p_hwcrhk_ModExp = 0;
  p_hwcrhk_RSA = 0;
  p_hwcrhk_RSALoadKey = 0;
  p_hwcrhk_RSAGetPublicKey = 0;
  p_hwcrhk_RSAUnloadKey = 0;
  p_hwcrhk_ModExpCRT = 0;
  p_hwcrhk_RandomBytes = 0;
  return uVar2;
}

