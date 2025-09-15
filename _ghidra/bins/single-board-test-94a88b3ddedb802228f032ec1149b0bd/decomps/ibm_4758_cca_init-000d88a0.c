
undefined4 ibm_4758_cca_init(void)

{
  char *filename;
  int line;
  
  if (dso == (DSO *)0x0) {
    filename = CCA4758_LIB_NAME;
    if (CCA4758_LIB_NAME == (char *)0x0) {
      filename = "CSUNSAPI";
    }
    dso = DSO_load((DSO *)0x0,filename,(DSO_METHOD *)0x0,0);
    if (dso == (DSO *)0x0) {
      if (CCA4758_lib_error_code == 0) {
        CCA4758_lib_error_code = ERR_get_next_error_library();
      }
      line = 0x122;
    }
    else {
      keyRecordRead = DSO_bind_func(dso,"CSNDKRR");
      if ((((keyRecordRead != (DSO_FUNC_TYPE)0x0) &&
           (randomNumberGenerate = DSO_bind_func(dso,"CSNBRNG"),
           randomNumberGenerate != (DSO_FUNC_TYPE)0x0)) &&
          (digitalSignatureGenerate = DSO_bind_func(dso,"CSNDDSG"),
          digitalSignatureGenerate != (DSO_FUNC_TYPE)0x0)) &&
         (((digitalSignatureVerify = DSO_bind_func(dso,"CSNDDSV"),
           digitalSignatureVerify != (DSO_FUNC_TYPE)0x0 &&
           (publicKeyExtract = DSO_bind_func(dso,"CSNDPKX"), publicKeyExtract != (DSO_FUNC_TYPE)0x0)
           ) && ((pkaEncrypt = DSO_bind_func(dso,"CSNDPKE"), pkaEncrypt != (DSO_FUNC_TYPE)0x0 &&
                 (pkaDecrypt = DSO_bind_func(dso,"CSNDPKD"), pkaDecrypt != (DSO_FUNC_TYPE)0x0))))))
      {
        hndidx = RSA_get_ex_new_index
                           (0,"IBM 4758 CCA RSA key handle",(undefined1 *)0x0,(undefined1 *)0x0,
                            (undefined1 *)0xd87bd);
        return 1;
      }
      if (CCA4758_lib_error_code == 0) {
        CCA4758_lib_error_code = ERR_get_next_error_library();
      }
      line = 0x135;
    }
    ERR_put_error(CCA4758_lib_error_code,0x66,0x67,"e_4758cca.c",line);
  }
  else {
    if (CCA4758_lib_error_code == 0) {
      CCA4758_lib_error_code = ERR_get_next_error_library();
    }
    ERR_put_error(CCA4758_lib_error_code,0x66,100,"e_4758cca.c",0x11c);
  }
  if (dso != (DSO *)0x0) {
    DSO_free(dso);
  }
  publicKeyExtract = (DSO_FUNC_TYPE)0x0;
  digitalSignatureVerify = (DSO_FUNC_TYPE)0x0;
  digitalSignatureGenerate = (DSO_FUNC_TYPE)0x0;
  keyRecordRead = (DSO_FUNC_TYPE)0x0;
  dso = (DSO *)0x0;
  pkaEncrypt = (DSO_FUNC_TYPE)0x0;
  pkaDecrypt = (DSO_FUNC_TYPE)0x0;
  randomNumberGenerate = (DSO_FUNC_TYPE)0x0;
  return 0;
}

