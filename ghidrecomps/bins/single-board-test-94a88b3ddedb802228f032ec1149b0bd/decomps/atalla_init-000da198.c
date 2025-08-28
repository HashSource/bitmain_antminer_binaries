
undefined4 atalla_init(void)

{
  DSO_FUNC_TYPE pDVar1;
  DSO_FUNC_TYPE pDVar2;
  DSO_FUNC_TYPE pDVar3;
  int iVar4;
  char *filename;
  undefined1 auStack_1018 [4100];
  
  if (atalla_dso == (DSO *)0x0) {
    filename = ATALLA_LIBNAME;
    if (ATALLA_LIBNAME == (char *)0x0) {
      filename = "atasi";
    }
    atalla_dso = DSO_load((DSO *)0x0,filename,(DSO_METHOD *)0x0,0);
    if (atalla_dso == (DSO *)0x0) {
      if (ATALLA_lib_error_code == 0) {
        ATALLA_lib_error_code = ERR_get_next_error_library();
      }
      iVar4 = 0x17f;
    }
    else {
      pDVar1 = DSO_bind_func(atalla_dso,"ASI_GetHardwareConfig");
      if (((pDVar1 != (DSO_FUNC_TYPE)0x0) &&
          (pDVar2 = DSO_bind_func(atalla_dso,"ASI_RSAPrivateKeyOpFn"), pDVar2 != (DSO_FUNC_TYPE)0x0)
          ) && (pDVar3 = DSO_bind_func(atalla_dso,"ASI_GetPerformanceStatistics"),
               pDVar3 != (DSO_FUNC_TYPE)0x0)) {
        p_Atalla_GetHardwareConfig = pDVar1;
        p_Atalla_RSAPrivateKeyOpFn = pDVar2;
        p_Atalla_GetPerformanceStatistics = pDVar3;
        iVar4 = (*pDVar1)(0,auStack_1018);
        if (iVar4 == 0) {
          return 1;
        }
        if (ATALLA_lib_error_code == 0) {
          ATALLA_lib_error_code = ERR_get_next_error_library();
        }
        ERR_put_error(ATALLA_lib_error_code,0x66,0x6b,"e_atalla.c",0x194);
        goto LAB_000da1ba;
      }
      if (ATALLA_lib_error_code == 0) {
        ATALLA_lib_error_code = ERR_get_next_error_library();
      }
      iVar4 = 0x189;
    }
    ERR_put_error(ATALLA_lib_error_code,0x66,0x69,"e_atalla.c",iVar4);
  }
  else {
    if (ATALLA_lib_error_code == 0) {
      ATALLA_lib_error_code = ERR_get_next_error_library();
    }
    ERR_put_error(ATALLA_lib_error_code,0x66,100,"e_atalla.c",0x170);
  }
LAB_000da1ba:
  if (atalla_dso != (DSO *)0x0) {
    DSO_free(atalla_dso);
  }
  p_Atalla_GetPerformanceStatistics = (DSO_FUNC_TYPE)0x0;
  p_Atalla_RSAPrivateKeyOpFn = (DSO_FUNC_TYPE)0x0;
  p_Atalla_GetHardwareConfig = (DSO_FUNC_TYPE)0x0;
  atalla_dso = (DSO *)0x0;
  return 0;
}

