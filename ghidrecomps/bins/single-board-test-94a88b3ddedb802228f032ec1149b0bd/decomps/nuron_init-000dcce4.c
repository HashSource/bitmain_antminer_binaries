
undefined4 nuron_init(void)

{
  undefined4 uVar1;
  char *filename;
  
  if (pvDSOHandle == (DSO *)0x0) {
    filename = NURON_LIBNAME;
    if (NURON_LIBNAME == (char *)0x0) {
      filename = "nuronssl";
    }
    pvDSOHandle = DSO_load((DSO *)0x0,filename,(DSO_METHOD *)0x0,2);
    if (pvDSOHandle == (DSO *)0x0) {
      if (NURON_lib_error_code == 0) {
        NURON_lib_error_code = ERR_get_next_error_library();
      }
      ERR_put_error(NURON_lib_error_code,0x66,0x68,"e_nuron.c",0x8b);
      uVar1 = 0;
    }
    else {
      pfnModExp = DSO_bind_func(pvDSOHandle,"nuron_mod_exp");
      if (pfnModExp == (DSO_FUNC_TYPE)0x0) {
        if (NURON_lib_error_code == 0) {
          NURON_lib_error_code = ERR_get_next_error_library();
        }
        ERR_put_error(NURON_lib_error_code,0x66,0x67,"e_nuron.c",0x91);
        uVar1 = 0;
      }
      else {
        uVar1 = 1;
      }
    }
  }
  else {
    if (NURON_lib_error_code == 0) {
      NURON_lib_error_code = ERR_get_next_error_library();
    }
    ERR_put_error(NURON_lib_error_code,0x66,100,"e_nuron.c",0x84);
    uVar1 = 0;
  }
  return uVar1;
}

