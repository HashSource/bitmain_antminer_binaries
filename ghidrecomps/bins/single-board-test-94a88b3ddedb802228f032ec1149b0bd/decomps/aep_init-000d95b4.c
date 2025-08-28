
undefined4 aep_init(void)

{
  DSO_FUNC_TYPE pDVar1;
  DSO_FUNC_TYPE pDVar2;
  DSO_FUNC_TYPE pDVar3;
  DSO_FUNC_TYPE pDVar4;
  DSO_FUNC_TYPE pDVar5;
  DSO_FUNC_TYPE pDVar6;
  DSO_FUNC_TYPE pDVar7;
  char *filename;
  int line;
  
  if (aep_dso == (DSO *)0x0) {
    filename = AEP_LIBNAME;
    if (AEP_LIBNAME == (char *)0x0) {
      filename = "aep";
    }
    aep_dso = DSO_load((DSO *)0x0,filename,(DSO_METHOD *)0x0,0);
    if (aep_dso == (DSO *)0x0) {
      if (AEPHK_lib_error_code == 0) {
        AEPHK_lib_error_code = ERR_get_next_error_library();
      }
      line = 0x1d4;
    }
    else {
      pDVar1 = DSO_bind_func(aep_dso,"AEP_ModExp");
      if ((((pDVar1 != (DSO_FUNC_TYPE)0x0) &&
           (pDVar2 = DSO_bind_func(aep_dso,"AEP_ModExpCrt"), pDVar2 != (DSO_FUNC_TYPE)0x0)) &&
          (pDVar3 = DSO_bind_func(aep_dso,"AEP_Finalize"), pDVar3 != (DSO_FUNC_TYPE)0x0)) &&
         (((pDVar4 = DSO_bind_func(aep_dso,"AEP_Initialize"), pDVar4 != (DSO_FUNC_TYPE)0x0 &&
           (pDVar5 = DSO_bind_func(aep_dso,"AEP_OpenConnection"), pDVar5 != (DSO_FUNC_TYPE)0x0)) &&
          ((pDVar6 = DSO_bind_func(aep_dso,"AEP_SetBNCallBacks"), pDVar6 != (DSO_FUNC_TYPE)0x0 &&
           (pDVar7 = DSO_bind_func(aep_dso,"AEP_CloseConnection"), pDVar7 != (DSO_FUNC_TYPE)0x0)))))
         ) {
        p_AEP_ModExp = pDVar1;
        p_AEP_ModExpCrt = pDVar2;
        p_AEP_Finalize = pDVar3;
        p_AEP_Initialize = pDVar4;
        p_AEP_OpenConnection = pDVar5;
        p_AEP_SetBNCallBacks = pDVar6;
        p_AEP_CloseConnection = pDVar7;
        return 1;
      }
      if (AEPHK_lib_error_code == 0) {
        AEPHK_lib_error_code = ERR_get_next_error_library();
      }
      line = 0x1e2;
    }
    ERR_put_error(AEPHK_lib_error_code,0x67,0x6f,"e_aep.c",line);
  }
  else {
    if (AEPHK_lib_error_code == 0) {
      AEPHK_lib_error_code = ERR_get_next_error_library();
    }
    ERR_put_error(AEPHK_lib_error_code,0x67,100,"e_aep.c",0x1cc);
  }
  if (aep_dso != (DSO *)0x0) {
    DSO_free(aep_dso);
  }
  p_AEP_CloseConnection = (DSO_FUNC_TYPE)0x0;
  p_AEP_SetBNCallBacks = (DSO_FUNC_TYPE)0x0;
  p_AEP_OpenConnection = (DSO_FUNC_TYPE)0x0;
  p_AEP_Initialize = (DSO_FUNC_TYPE)0x0;
  p_AEP_Finalize = (DSO_FUNC_TYPE)0x0;
  p_AEP_ModExpCrt = (DSO_FUNC_TYPE)0x0;
  p_AEP_ModExp = (DSO_FUNC_TYPE)0x0;
  aep_dso = (DSO *)0x0;
  return 0;
}

