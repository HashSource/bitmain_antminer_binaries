
undefined4 cswift_finish(void)

{
  int iVar1;
  undefined4 uVar2;
  
  if (CSWIFT_LIBNAME != (void *)0x0) {
    CRYPTO_free(CSWIFT_LIBNAME);
  }
  CSWIFT_LIBNAME = (void *)0x0;
  if (cswift_dso == (DSO *)0x0) {
    if (CSWIFT_lib_error_code == 0) {
      CSWIFT_lib_error_code = ERR_get_next_error_library();
    }
    ERR_put_error(CSWIFT_lib_error_code,0x67,0x6a,"e_cswift.c",0x1c2);
    uVar2 = 0;
  }
  else {
    iVar1 = DSO_free(cswift_dso);
    if (iVar1 == 0) {
      if (CSWIFT_lib_error_code == 0) {
        CSWIFT_lib_error_code = ERR_get_next_error_library();
      }
      ERR_put_error(CSWIFT_lib_error_code,0x67,0x6c,"e_cswift.c",0x1c6);
      uVar2 = 0;
    }
    else {
      uVar2 = 1;
      cswift_dso = (DSO *)0x0;
      p_CSwift_AcquireAccContext = 0;
      p_CSwift_AttachKeyParam = 0;
      p_CSwift_SimpleRequest = 0;
      p_CSwift_ReleaseAccContext = 0;
    }
  }
  return uVar2;
}

