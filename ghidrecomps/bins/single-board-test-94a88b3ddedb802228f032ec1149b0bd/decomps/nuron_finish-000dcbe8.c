
undefined4 nuron_finish(void)

{
  int iVar1;
  undefined4 uVar2;
  
  if (NURON_LIBNAME != (void *)0x0) {
    CRYPTO_free(NURON_LIBNAME);
  }
  NURON_LIBNAME = (void *)0x0;
  if (pvDSOHandle == (DSO *)0x0) {
    if (NURON_lib_error_code == 0) {
      NURON_lib_error_code = ERR_get_next_error_library();
    }
    ERR_put_error(NURON_lib_error_code,0x65,0x69,"e_nuron.c",0x9c);
    uVar2 = 0;
  }
  else {
    iVar1 = DSO_free(pvDSOHandle);
    if (iVar1 == 0) {
      if (NURON_lib_error_code == 0) {
        NURON_lib_error_code = ERR_get_next_error_library();
      }
      ERR_put_error(NURON_lib_error_code,0x65,0x66,"e_nuron.c",0xa0);
      uVar2 = 0;
    }
    else {
      uVar2 = 1;
      pvDSOHandle = (DSO *)0x0;
      pfnModExp = 0;
    }
  }
  return uVar2;
}

