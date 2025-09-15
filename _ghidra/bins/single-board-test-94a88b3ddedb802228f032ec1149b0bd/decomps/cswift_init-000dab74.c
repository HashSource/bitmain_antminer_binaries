
undefined4 cswift_init(void)

{
  DSO_FUNC_TYPE pDVar1;
  DSO_FUNC_TYPE pDVar2;
  DSO_FUNC_TYPE pDVar3;
  DSO_FUNC_TYPE pDVar4;
  int iVar5;
  char *filename;
  undefined4 local_1c [2];
  
  if (cswift_dso == (DSO *)0x0) {
    filename = CSWIFT_LIBNAME;
    if (CSWIFT_LIBNAME == (char *)0x0) {
      filename = "swift";
    }
    cswift_dso = DSO_load((DSO *)0x0,filename,(DSO_METHOD *)0x0,0);
    if (cswift_dso == (DSO *)0x0) {
      if (CSWIFT_lib_error_code == 0) {
        CSWIFT_lib_error_code = ERR_get_next_error_library();
      }
      iVar5 = 0x195;
    }
    else {
      pDVar1 = DSO_bind_func(cswift_dso,"swAcquireAccContext");
      if ((((pDVar1 != (DSO_FUNC_TYPE)0x0) &&
           (pDVar2 = DSO_bind_func(cswift_dso,"swAttachKeyParam"), pDVar2 != (DSO_FUNC_TYPE)0x0)) &&
          (pDVar3 = DSO_bind_func(cswift_dso,"swSimpleRequest"), pDVar3 != (DSO_FUNC_TYPE)0x0)) &&
         (pDVar4 = DSO_bind_func(cswift_dso,"swReleaseAccContext"), pDVar4 != (DSO_FUNC_TYPE)0x0)) {
        p_CSwift_AcquireAccContext = pDVar1;
        p_CSwift_AttachKeyParam = pDVar2;
        p_CSwift_SimpleRequest = pDVar3;
        p_CSwift_ReleaseAccContext = pDVar4;
        iVar5 = (*pDVar1)(local_1c);
        if (iVar5 == 0) {
          (*p_CSwift_ReleaseAccContext)(local_1c[0]);
          return 1;
        }
        if (CSWIFT_lib_error_code == 0) {
          CSWIFT_lib_error_code = ERR_get_next_error_library();
        }
        ERR_put_error(CSWIFT_lib_error_code,0x68,0x6c,"e_cswift.c",0x1ac);
        goto LAB_000dab92;
      }
      if (CSWIFT_lib_error_code == 0) {
        CSWIFT_lib_error_code = ERR_get_next_error_library();
      }
      iVar5 = 0x1a0;
    }
    ERR_put_error(CSWIFT_lib_error_code,0x68,0x6a,"e_cswift.c",iVar5);
  }
  else {
    if (CSWIFT_lib_error_code == 0) {
      CSWIFT_lib_error_code = ERR_get_next_error_library();
    }
    ERR_put_error(CSWIFT_lib_error_code,0x68,100,"e_cswift.c",399);
  }
LAB_000dab92:
  if (cswift_dso != (DSO *)0x0) {
    DSO_free(cswift_dso);
    cswift_dso = (DSO *)0x0;
  }
  p_CSwift_ReleaseAccContext = (DSO_FUNC_TYPE)0x0;
  p_CSwift_SimpleRequest = (DSO_FUNC_TYPE)0x0;
  p_CSwift_AttachKeyParam = (DSO_FUNC_TYPE)0x0;
  p_CSwift_AcquireAccContext = (DSO_FUNC_TYPE)0x0;
  return 0;
}

