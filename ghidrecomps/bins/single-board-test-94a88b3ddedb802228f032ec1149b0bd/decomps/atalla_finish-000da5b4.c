
undefined4 atalla_finish(void)

{
  int iVar1;
  undefined4 uVar2;
  
  if (ATALLA_LIBNAME != (void *)0x0) {
    CRYPTO_free(ATALLA_LIBNAME);
  }
  ATALLA_LIBNAME = (void *)0x0;
  if (atalla_dso == (DSO *)0x0) {
    if (ATALLA_lib_error_code == 0) {
      ATALLA_lib_error_code = ERR_get_next_error_library();
    }
    ERR_put_error(ATALLA_lib_error_code,0x65,0x69,"e_atalla.c",0x1a7);
    uVar2 = 0;
  }
  else {
    iVar1 = DSO_free(atalla_dso);
    if (iVar1 == 0) {
      if (ATALLA_lib_error_code == 0) {
        ATALLA_lib_error_code = ERR_get_next_error_library();
      }
      ERR_put_error(ATALLA_lib_error_code,0x65,0x6b,"e_atalla.c",0x1ab);
      uVar2 = 0;
    }
    else {
      uVar2 = 1;
      atalla_dso = (DSO *)0x0;
      p_Atalla_GetHardwareConfig = 0;
      p_Atalla_RSAPrivateKeyOpFn = 0;
      p_Atalla_GetPerformanceStatistics = 0;
    }
  }
  return uVar2;
}

